//
// Created by coinxu on 05/09/17.
//

#include <stdio.h>
#include "tree.h"

static void print_item(Item item) {
    printf("Pet.name -> %s\n", item.petname);
}

int main(void) {
    short i = 0;
    const short LEN = 6;
    const Item pets[LEN] = {
            {"Diudiu",  "Cat"},
            {"Yumi",    "Cat"},
            {"Bibi",    "Cat"},
            {"Xiaohei", "Dog"},
            {"Maomao",  "Dog"},
            {"Kaixin",  "Dog"}
    };

    Tree tree;
    Item pet;
    initialize(&tree);

    printf("add pet in tree\n");
    for (i = 0; i < LEN; i++) {
        pet = pets[i];
        if (tree_add(&pet, &tree)) {
            printf("success add pet: %s\n", pet.petname);
        } else {
            printf("failed add pet: %s\n", pet.petname);
        }
    }
    printf("Pets count: %d\n", tree_item_count(&tree));

    printf("check pet in tree\n");
    for (i = 0; i < LEN; i++) {
        pet = pets[i];
        if (in_tree(&pet, &tree)) {
            printf("pet: %s in tree\n", pet.petname);
        } else {
            printf("pet: %s not in tree\n", pet.petname);
        }
    }

    printf("traverse tree\n");
    traverse(&tree, print_item);

    //   Diudiu
    //   /    \
    // Bibi   Yumi
    //         /
    //      Xiaohei
    //        /
    //     Maomao
    //       /
    //     Kaixin
    return 0;
}
