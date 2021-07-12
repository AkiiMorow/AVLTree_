//
//  main.c
//  AVL_Tree
//
//  Created by Michael Strommer on 02.07.21.
//

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"
#include <stdbool.h>

int main() {
    // test your implementation here
    // no test cases will be provided this time!

    //an example tree.

    binTree *tree_A = t_init();

    insert(tree_A, 3, "3");
    insert(tree_A, 2, "2");
    insert(tree_A, 1, "1");     //balance = -2. -> Right Rotation
    insert(tree_A, 10, "10");
    insert(tree_A, 15, "15");   //balance = 2. -> Left Rotation



    preOrder(tree_A->root);


}

