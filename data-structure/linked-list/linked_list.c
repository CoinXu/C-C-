//
// Created by coinxu on 2/14/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

int main(void){
    struct film * head = NULL;
    struct film *prev = NULL, * current;
    char input[TITLE_SIZE];

    puts("Enter first movie title: ");

    while (gets(input) != NULL && input[0] != '\0'){
        current = (struct film *)malloc(sizeof(struct film));
        // linked list
        if(head == NULL)
            head = current;
        else
            prev->next = current;

        current->next = NULL;
        // linked list end

        strcpy(current->title, input);
        puts("Enter your rating <0-10>: ");
        scanf("%d", &current->rating);

        while (getchar() != '\n')
            continue;

        puts("Enter next movie title: ");
        prev = current;
    }

    if(head == NULL)
        printf("No data entered. ");
    else
        printf("Here is the moive list: \n");

    current = head;
    // output content
    while (current != NULL){
        printf("Movie: %s Rating: %d\n", current->title, current->rating);
        current = current->next;
    }

    // clean
    current = head;
    while (current != NULL){
        current = current->next;
        free(current);
    }

    return 0;
}