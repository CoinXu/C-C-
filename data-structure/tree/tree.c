//
// Created by asd on 17-9-4.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"

typedef struct pair {
    Node *parent;
    Node *child;
} Pair;

/**
 * 确定节点是否存在左边
 * 注：strcmp(a, b)
 * 如果 a < b 返回负数
 * 如果 a == b 返回0
 * 如果 a > b 返回正数
 * 此处先按petname排序，再按petkind排序
 * 如果还是相等，则表示二者为相同的项
 * @param base
 * @param comp
 * @return
 */
static bool to_left(const Item *base, const Item *comp) {
    int ret;
    if ((ret = strcmp(base->petname, comp->petname)) < 0) {
        return true;
    } else if (ret == 0 && strcmp(base->petkind, comp->petkind) < 0) {
        return false;
    }
    return false;
}

static bool to_right(const Item *base, const Item *comp) {
    int ret;
    if ((ret = strcmp(base->petname, comp->petname)) > 0) {
        return true;
    } else if (ret == 0 && strcmp(base->petkind, comp->petkind) > 0) {
        return false;
    }
    return false;
}

/**
 * 初始化节点
 * 如果初始化失败返回NULL
 */
static Node *make_node(const Item *item) {
    Node *node;
    node = (Node *) malloc(sizeof(Node);

    if (node != NULL) {
        node->item = *item;
        node->left = node->right = NULL;
    }
    return node;
}

/**
 * 反回包含该项目的节点(child)及父节点(parent)
 * 如果没有父节点，则parent为NULL
 * @param pair
 * @param tree
 * @return
 */
static Pair seek_item(const Item *pair, const Tree *tree) {
    Pair look;
    look.parent = NULL;
    look.child = tree->root;

    if (look.child == NULL) {
        return look;
    }

    while (look.child != NULL) {
        if (to_left(pair, &(look.child->item))) {
            look.parent = look.child;
            look.child = look.child->left;
        } else if (to_right(pair, &(look.child->item))) {
            look.parent = look.child;
            look.child = look.child->right;
        } else {
            break;
        }
    }

    return look;
}

/**
 * 将一个节点添加到一个根节点下
 * 此时需要使用to_left或to_right来决定是放在左树还是右树
 * 确定放置位置后，需要判断位置是否为空
 * 如果为空，则直接设置
 * 否则需要继续向下查找，直到找到child为NULL的节点
 */
static void add_node(Node *node, Node *root) {
    if (to_left(&node->item, &root->item)) {
        if (root->left == NULL) {
            root->left = node;
        } else {
            add_node(node, root->left);
        }
    } else if (to_right(&node->item, &root->item)) {
        if (root->right == NULL) {
            root->right = node;
        } else {
            add_node(node, root->right);
        }
    } else {
        fprintf(stderr, "location error in add_node()\n");
        exit(1);
    }
}

/**
 * 初始化tree
 */
void initialize(Tree *tree) {
    tree->root = NULL;
    tree->size = 0;
}

/**
 * 是否为空tree
 */
bool tree_is_empty(const Tree *tree) {
    return tree->size == 0;
}

/**
 * 是否已满
 */
bool tree_is_full(const Tree *tree) {
    return tree->size == MAXITEMS;
}

/**
 * 是否存在于树中
 */
bool in_tree(const Item *item, const Tree *tree) {
    return seek_item(item, tree).child == NULL;
}

/**
 * 总记录数
 */
int tree_item_count(const Tree *tree) {
    return tree->size;
}

/**
 * 添加项目
 */
int tree_add(const Item *item, Tree *tree) {

    Node *node;

    if (tree_is_full(tree)) {
        fprintf(stderr, "Tree is full.\n");
        return false;
    }

    if (seek_item(item, tree).child != NULL) {
        fprintf(stderr, "Attempted to add duplicate item\n");
        return false;
    }

    node = make_node(item);

    if (node == NULL) {
        fprintf(stderr, "Couldn't create node\n");
        return false;
    }

    tree->size++;

    if (tree->root == NULL) {
        tree->root = node;
    } else {
        add_node(node, tree->root);
    }
    return true;
}


/**
 * 删除项目
 * 1. 查找节点
 * 2. 删除节点并重新关联父节点
 */

/**
 * 删除节点
 */
static void delete_node(Node **ptr) {
    Node *temp;
    puts((*ptr)->item.petname);

    if ((*ptr)->left == NULL) {
        // 如果无左子节点，将右子节点放在父节点的位置
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    } else if ((*ptr)->right == NULL) {
        // 如果无右子节点，将左子节点放在父节点的位置
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    } else {
        // 左右子节点都存在时
        // 将左子节点放在父节点的位置
        // 右子节点挂在最左子节点下
        for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right) {
            continue;
        }
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
}

/**
 * 查找节点并调用删除
 */
bool delete_item(const Item *item, Tree *tree) {
    Pair look;
    look = seek_item(item, tree);

    if (look.child == NULL) {
        return false;
    }

    if (look.parent == NULL) {
        // 删除root节点
        delete_node(&tree->root);
    } else if (look.parent->left == look.child) {
        // 删除左节点
        delete_node(&look.parent->left);
    } else {
        // 删除右节点
        delete_node(&look.parent->right);
    }

    tree->size--;
    return true;
}

/**
 * 遍历树
 */
static void in_order(const Node *root, void (*fn)(Item item)) {
    if (root != NULL) {
        in_order(root->left, fn);
        (*fn)(root->item);
        in_order(root->right, fn);
    }
}

void traverse(const Tree *tree, void (*fn)(Item item)) {
    if (tree != NULL) {
        in_order(tree->root, fn);
    }
}




