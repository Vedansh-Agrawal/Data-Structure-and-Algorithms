#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

node *createnode(int A)
{
    node *temp = malloc(sizeof(node));
    temp->number = A;
    temp->right = NULL;
    temp->left = NULL;
    temp->up = NULL;

    return temp;
}

void addnode(node **root, int A, int B, int C, node *nodes[])
{
    if (C == 1)
    {
        nodes[A - 1]->left = nodes[B - 1];
        nodes[B - 1]->up = nodes[A - 1];
    }

    else
    {
        nodes[A - 1]->right = nodes[B - 1];
        nodes[B - 1]->up = nodes[A - 1];
    }

    if (nodes[A - 1]->up == NULL)
        *root = nodes[A - 1];
}

void preorder(node *root,int arr[],int *i)
{
    if (root == NULL)
    {
        return;
    }

    arr[*i] = root->number;
    (*i) += 1;
    preorder(root->left,arr,i);
    preorder(root->right,arr,i);
}