#ifndef TREE_H
#define TREE_H

typedef struct tree
{
    int number;
    struct tree *left;
    struct tree *right;
} node;

node *createnode(int A);
node *createtree(int n, int array[]);


#endif