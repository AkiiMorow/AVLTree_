//
//  bintree.h
//  AVL_Tree
//
//  Created by Michael Strommer on 02.07.21.
//

#ifndef _bintree
#define _bintree

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#undef max


typedef struct node_ {
    int key;
    char *data;
    struct node_ *left;
    struct node_ *right;
    int balance;
} node;

typedef struct binTree_ {
    int size;
    node *root;
} binTree;

// Funktionsprototypen

binTree *t_init(void);
node *insertNode(node *, int, const char *);
node *insert(binTree *, int, const char *);
int treeDepth(node *);

void preOrder(struct node_ *start);
node *RotateLeft(node *base, node *rightChild);
node *RotateRight(node *base, node *leftChild);
node *balanceNodes(node *start);
int max(int a, int b);




// TODO: Rotationsprototypen

#endif /* bintree_h */
