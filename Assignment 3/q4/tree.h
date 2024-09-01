#ifndef TREE_H
#define TREE_H

typedef struct tree
{
    int number;
    struct tree *left;
    struct tree *right;
    struct tree *up;
} node;

void addnode(node **root,int A,int B,int C, node *nodes[]);
node *createnode(int A);
void preorder(node *root,int arr[],int *i);


#endif