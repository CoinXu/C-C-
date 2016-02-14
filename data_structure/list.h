//
// Created by coinxu on 2/14/16.
//

#ifndef C_C_LIST_H
#define C_C_LIST_H

#include <stdbool.h>

#define TITLE_SIZE 45
struct film {
    char title[TITLE_SIZE];
    int rating;
};

typedef struct film Item;
typedef struct node {
    Item item;
    struct node *next;
};

typedef struct node Node;
typedef Node *List;

void InitializeList(List *plist);

bool ListIsEmpty(const List *plist);

bool ListIsFull(const List *plist);

unsigned int ListItemCount(const List *plist);

bool AddItem(Item item, List *plist);

void Traverse(const List *plist, void(*fn)(Item item));

void EmptyTheList(List *plist);

#endif //C_C_LIST_H
