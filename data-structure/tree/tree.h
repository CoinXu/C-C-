//
// Created by asd on 17-9-4.
//

#ifndef ADT_TREE
#define ADT_TREE

#include <stdbool.h>

#define MAXITEMS 10

typedef struct item {
    char petname[20];
    char petkind[20];
} Item;

typedef struct node {
    Item item;
    struct node *left;
    struct node *right;
} Node;

typedef struct tree {
    Node *root;
    int size;
} Tree;

/**
 * 初始化Tree指针
 */
void initialize(Tree *tree);

/**
 * is empty
 */
bool tree_is_empty(const Tree *tree);

/**
 * is full
 */
bool tree_is_full(const Tree *tree);

/**
 * item count
 */
int tree_item_count(const Tree *tree);

/**
 * add item
 */
int tree_add(const Item *item, Tree *tree);

/**
 * in tree
 */
bool in_tree(const Item *item, const Tree *tree);

/**
 * delete item
 */
int tree_delete(const Item *item, const Tree *tree);

/**
 * traverse
 */
void traverse(const Tree *tree, void (*fn)(Item item));

/**
 * delete all
 */
void tree_delete_all(const Tree *tree);

#endif //ADT_TREE
