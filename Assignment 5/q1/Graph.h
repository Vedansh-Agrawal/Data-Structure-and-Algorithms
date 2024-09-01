#ifndef _GRAPH_H
#define _GRAPH_H_

typedef struct graph_node
{
    int number;
    int colour;
    struct graph_node* next; 
}node;

void insert(node *graph_node,int number,int colour);
int search(node *arr[],int x, int y, int m, int n);
node *searchcolour(node *arr,int colour, int y[]);

#endif