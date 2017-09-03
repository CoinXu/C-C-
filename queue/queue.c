//
// Created by coinxu on 03/09/17.
//

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

/* Inner functions */

static void copy_to_node(Item item, Node *pn);

static void copy_to_item(Node *pn, Item *pi);

/* Inter functions implements */
void copy_to_node(Item item, Node *pn) {
    pn->item = item;
}

void copy_to_item(Node *pn, Item *pi) {
    *pi = pn->item;
}

/** Queue Implements */
void initialize(Queue *pq) {
    pq->front = pq->rear = NULL;
    pq->items = 0;
}

bool queue_is_full(const Queue *pq) {
    return pq->items == MAXQUEUE;
}

bool queue_is_empty(const Queue *pq) {
    return pq->items == 0;
}

int queue_item_count(const Queue *pq) {
    return pq->items;
}

bool en_queue(Item item, Queue *pq) {
    if (queue_is_full(pq)) {
        return false;
    }

    Node *pnew;
    pnew = (Node *) malloc(sizeof(Node));

    // Unable memory
    if (pnew == NULL) {
        fprintf(stderr, "Unable to allocate memory!\n");
        exit(1);
    }

    copy_to_node(item, pnew);
    pnew->next = NULL;

    // 如果是空队列，则将pnew设置为queue.front
    // 否则放置在queue.rear之后
    if (queue_is_empty(pq)) {
        pq->front = pnew;
    } else {
        pq->rear->next = pnew;
    }

    // 记录尾端的位置
    pq->rear = pnew;
    // 更新计数
    pq->items++;

    return true;
}

bool de_queue(Item *pitem, Queue *pq) {
    if (queue_is_empty(pq)) {
        return false;
    }

    copy_to_item(pq->front, pitem);

    // 更新 pq->front
    Node *pt = pq->front;
    pq->front = pt->next;

    free(pt);
    pq->items--;

    if (queue_is_empty(pq)) {
        pq->rear = NULL;
    }

    return true;
}

void empty_the_queue(Queue *pq) {
    Item dummy;
    while (!queue_is_empty(pq)) {
        de_queue(&dummy, pq);
    }
}

