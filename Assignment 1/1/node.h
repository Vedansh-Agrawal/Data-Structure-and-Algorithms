#ifndef NODE_H
#define NODE_H

typedef struct node_ node;

struct node_
{
    int data;
    node* prev;
    node* next;
};

#endif