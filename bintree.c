#define _CRT_SECURE_NO_WARNINGS

//
//  bintree.c
//  AVL_Tree
//
//  Created by Michael Strommer on 02.07.21.
//

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"


binTree *t_init(){
    binTree *tmp = (binTree *)malloc(sizeof(binTree));
    tmp->root = NULL;
    tmp->size = 0;
    return tmp;
}

// TODO: double pointer einführen oder über return Werte lösen
node *insertNode(node *start, int key, const char *data) {
    node *newNode;
    if (start == NULL) {
        newNode = (node *) malloc(sizeof(node));
        if (newNode != NULL) {
            newNode->data = (char *) malloc(strlen(data) + 1);
            strcpy(newNode->data, data);
            newNode->key = key;
            newNode->right = newNode->left = NULL;
            newNode->balance = 0;
        }
        return newNode;
    }
    if (key < start->key)
    {
        start->left = insertNode(start->left, key, data);
    }
    else
    {
        start->right = insertNode(start->right, key, data);
    }

    start = balanceNodes(start);

    return start;


}

void preOrder(struct node_ *start)
{
    if (start != NULL)
    {
        printf("%d ", start->key);
        preOrder(start->left);
        preOrder(start->right);
    }
}

// TODO: Implementierung Rotationen

//Rotation Left
node *RotateLeft(node *base, node *rightChild) {
    node *temp = base;
    base = rightChild;
    temp->right = base->left;
    base->left = temp;
    return base;
}

//Rotation Right
node *RotateRight(node *base, node *leftChild) {
    node *temp = base;
    base = leftChild;
    temp->left = base->right;
    base->right = temp;
    return base;
}



node *balanceNodes(node *start) {

    // TODO: Schritte 1-3
    // 1. Balancefaktor für den "start" Knoten mit Hilfe von treeDepth berechnen
    // 2. Überprüfung der Lastigkeit
    // 3. Ausführung der einzelnen Rotationen

    start->balance = treeDepth(start->right) - treeDepth(start->left);


    //Left Rotation or Right-Left Rotation

    if (start->balance > 1) {
        if (start->right->balance < 0) RotateRight(start->right, start->right->left);
        start = RotateLeft(start, start->right);


    }

    //Right Rotation or Left-Right Rotation

    else if (start->balance < -1) {
        if (start->left->balance > 0) RotateLeft(start->left, start->left->right);
        start = RotateRight(start, start->left);
    }

    return start;

}

node *insert(binTree *t, int key, const char *data){
    node *newNode;
    t->root = insertNode(t->root, key, data);
    t->size++;
    return newNode;
}

int max(int a, int b) {
if (a > b)
    return a;
else
    return b;
}

int treeDepth(node *start){
    if (start == NULL) {
        return 0;
    }
    else {
        return 1 +  max(treeDepth(start->left),
                        treeDepth(start->right));
    }
}



