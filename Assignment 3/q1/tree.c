#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

node *createnode(int A)
{
    node *temp = malloc(sizeof(node));
    temp->number = A;
    temp->right = NULL;
    temp->left = NULL;

    return temp;
}

node *createtree(int n, int arr[])
{
    node *tree;
    tree = createnode(arr[0]);
    node *point[2 * n];

    int i = 1, x = 0, y = 1;

    while (i < n)
    {
        if (arr[i] == 0)
        {
            point[x]->left = NULL;
            i += 1;
        }
        else
        {
            point[x]->left = createnode(arr[i]);
            i++;
            point[y] = point[x]->left;
            y++;
        }

        if (arr[i] == 0)
        {
            point[x]->right = NULL;
            i++;
        }
        else
        {
            point[x]->right = createnode(arr[i]);
            i++;
            point[y] = point[x]->right;
            y++;
        }
        x++;
    }

    for (int j = x; j < y; j++)
    {
        point[j]->left = NULL;
        point[i]->right = NULL;
    }

    return tree;
}
