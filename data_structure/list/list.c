//
// Created by coinxu on 2/14/16.
//

#include <stdlib.h>
#include "list.h"

static void CopyToNode(Item item, Node *node);

// implements
void InitializeList(List *list) {
    *list = NULL;
}

bool ListIsEmpty(const List *list) {
    return *list == NULL;
}

bool ListIsFull(const List *list) {
    Node *node;
    bool isFull;

    node = (Node *) malloc(sizeof(Node));
    isFull = node == NULL;

    free(node);
    return isFull;
}

unsigned int ListItemCount(const List *list) {
    unsigned int count = 0;
    Node *c = *list;
    while (c != NULL) {
        ++count;
        c = c->next;
    }
    return count;
}

bool AddItem(Item item, List *list) {
    Node *pnew;
    Node *scan = *list;
    pnew = (Node *) malloc(sizeof(Node));
    if (pnew == NULL)
        return false;

    CopyToNode(item, pnew);
    pnew->next = NULL;

    if (scan == NULL)
        *list = pnew;
    else {
        while (scan->next != NULL)
            scan = scan->next;
        scan->next = pnew;
    }

    return true;
}

void Traverse(const List *list, void(*fn)(Item item)) {
    Node *node = *list;
    while (node != NULL) {
        (*fn)(node->item);
        node = node->next;
    }
}

void EmptyTheList(List *list) {
    Node *psave;
    while (*list != NULL) {
        psave = (*list)->next;
        free(*list);
        *list = psave;
    }
}

void CopyToNode(Item item, Node *node) {
    node->item = item;
}