//
// Created by coinxu on 10/09/17.
//

#include <stdio.h>
#include <stdlib.h>

int *paf(void);

int *paf(void) {
    int *arr;
    arr = calloc(2, sizeof(int));
    // TODO
    // free arr at outer
    return arr;
}


int main(void) {

    // char
    char *c = "char point";
    char direct_c[] = "directy chars";
    printf("char pointer declare: %s -> %s\n", c, direct_c);

    // int
    int *i;
    int k = 0;
    i = &k;
    printf("int pointer declare: %d -> %d\n", *i, k);

    // array
    int *p;
    int arr[] = {1, 2, 3, 4};

    p = arr;
    printf("p[1] -> %d\n", p[1]);
    printf("*(p + 1) -> %d\n", *(p + 1));
    p = arr + 1;
    printf("*p -> %d\n", *p);

    int a[2][3][5];
    int (*ap)[3][5];
    int (*bp)[5] = a[1];
    int *cp = a[1][1];
    int u = a[1][1][1];


    return 0;
}
