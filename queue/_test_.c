//
// Created by coinxu on 03/09/17.
//

#include <stdio.h>
#include "queue.h"

int main(void) {
    Queue line;
    Item temp;

    int counter = MAXQUEUE;

    initialize(&line);

    while (counter >= 0) {
        temp = counter--;
        if (queue_is_full(&line)) {
            printf("Queue is full\n");
            break;
        }
        en_queue(temp, &line);
    }

    printf("Now log all items\n");
    printf("Queue->count: %d\n", queue_item_count(&line));

    while (!queue_is_empty(&line)) {
        de_queue(&temp, &line);
        printf("Item is -> %d\n", temp);
    }
    // clean
    empty_the_queue(&line);

    return 0;
}