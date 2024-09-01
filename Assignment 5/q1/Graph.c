#include "Graph.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insert(node *y, int number, int colour)
{
    node *x;
    x = (node *)malloc(sizeof(node));
    x->number = number;
    x->colour = colour;
    x->next = y;
    y = x;
}

int search(node *arr[], int x, int y, int m, int n)
{
    int a[m], ans = 0;
    memset(a, 0, m * sizeof(int));
    node *b;
    b = arr[x - 1];

    while (b != NULL)
    {
        int colour = b->colour;
        int c[n];
        memset(c, 0, n * sizeof(int));

        c[x - 1] = 1;
        c[b->number - 1] = 1;
        node *d = b;

        if (b->number == y)
        {
            a[colour - 1] = 1;
            do
            {
                b = b->next;
            } while (b != NULL && a[b->colour - 1] == 1);
            continue;
        }

        while ((d = searchcolour(arr[d->number - 1], colour, c)) != NULL && d->number != y)
        {
            c[d->number - 1] = 1;
        }

        if (d != NULL)
        {
            a[colour - 1] = 1;
        }

        do
        {
            b = b->next;
        } while (b != NULL && a[b->colour - 1] == 1);
    }

    for (int i = 0; i < m; i++)
    {
        if (a[i] == 1)
        {
            ans++;
        }
    }

    return ans;
}

node *searchcolour(node *arr, int colour, int y[])
{
    node *x;
    x = arr;
    while (x != NULL)
    {
        if (x->colour == colour && y[x->number - 1] == 0)
        {
            break;
        }
        x = x->next;
    }

    return x;
}