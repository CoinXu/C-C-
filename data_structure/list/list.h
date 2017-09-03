//
// Created by coinxu on 2/14/16.
//

#ifndef ADT_LIST
#define ADT_LIST
#define TSIZE 45

#include <stdbool.h>

// define film struct
struct film {
    char title[TSIZE];
    int rating;
};
typedef struct film Item;

// define node
typedef struct node {
    Item item;
    struct node *next;
};
typedef struct node Node;
typedef Node *List;

/**
 * Initialize list point
 */
void InitializeList(List *plist);

/**
 * Ensure list empty status
 */
bool ListIsEmpty(const List *plist);

/**
 * Ensure list full status
 */
bool ListIsFull(const List *plist);

/**
 * Count list items
 */
unsigned int ListItemCount(const List *plist);

/**
 * Add one to list
 */
bool AddItem(Item item, List *plist);

/**
 * pass each item in callback
 */
void Traverse(const List *plist, void(*fn)(Item item));

/**
 * clean list
 */
void EmptyTheList(List *plist);

#endif
