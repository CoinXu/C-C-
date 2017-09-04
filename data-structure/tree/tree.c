//
// Created by asd on 17-9-4.
//

#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

/**
 * 确定节点是否存在左边
 * @param base
 * @param comp
 * @return
 */
static bool to_left(const Item *base, const Item *comp) {
    // TODO
    return base->petname > comp->petname;
}

/**
 * 确定节点是否存在右边
 * @param base
 * @param comp
 * @return
 */
static bool to_right(const Item *base, const Item *comp) {
    // TODO
    return base->petname > comp->petname;
}

typedef struct pair {
    Node *parent;
    Node *child;
} Pair;


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

void initialize(Tree *tree) {
    tree->root = NULL;
    tree->size = 0;
}

bool tree_is_empty(const Tree *tree) {
    return tree->size == 0;
}

bool tree_is_full(const Tree *tree) {
    return tree->size == MAXITEMS;
}

int tree_item_count(const Tree *tree) {
    return tree->size;
}

int tree_add(const Item *item, const Tree *tree) {
    Node *node;

    if (tree_is_full(tree)) {
        printf("Tree is full.\n");
        return false;
    }


}