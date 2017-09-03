//
// Created by coinxu on 2/14/16.
//

#ifndef C_C_LINKED_LIST_H
#define C_C_LINKED_LIST_H
#define TITLE_SIZE 10
struct film {
    char title[TITLE_SIZE];
    int rating;
    struct film * next;
};

#endif //C_C_LINKED_LIST_H
