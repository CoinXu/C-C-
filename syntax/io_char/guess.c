//
// Created by coinxu on 12/12/15.
//

#include "stdio.h"

int main(void) {
    int guess = 1;
    printf("Pick an integer from 1 to 100. I will try to guess ");
    printf("it.\nRespond with a y if my guess is rigth and with");
    printf("\nan n if it is wrong.\n");

    printf("Uh...is your number %d?\n", guess);

    while (getchar() != 'y'){
        printf("Well, then. is it %d?\n", ++guess);
    }

    printf("I kew I could do it!\n");
    return 0;
}
