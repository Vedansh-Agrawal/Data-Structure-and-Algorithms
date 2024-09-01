#ifndef _QUEUE_H
#define _QUEUE_H

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

int dequeue(node **head);
void enqueue(node **tail, node **head, int x);
int front(node *head);
int isEmpty(node *head);
int size(node *tail);

#endif