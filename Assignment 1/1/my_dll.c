#include <stdio.h>
#include <stdlib.h>
#include "my_dll.h"
#include "node.h"

void insert(my_dll *list, int x)
{
    node *temp = malloc(sizeof(node));
    temp->data = x;

    if (list->root == NULL)
    {
        temp->next = list->root;
        temp->prev = NULL;
        list->root = temp;
        list->tail = temp;
    }
    else
    {
        temp->next = NULL;
        temp->prev = list->tail;
        list->tail->next = temp;
        list->tail = temp;
    }
}

void insert_at(my_dll *list, int x, int i)
{
    node *temp = malloc(sizeof(node));
    node *ptr;
    node *ptr1;
    ptr = list->root;
    temp->data = x;

    int count = 0;
    if (i == get_size(list))
    {
        insert(list, x);
        return;
    }

    if (i == 0)
    {
        list->root->prev = temp;
        temp->prev = NULL;
        temp->next = list->root;
        list->root = temp;
        return;
    }

    while (count != i - 1)
    {
        ptr = ptr->next;
        count++;
    }
    ptr1 = ptr->next;

    ptr->next = temp;
    temp->prev = ptr;

    ptr1->prev = temp;
    temp->next = ptr1;
}

void delete (my_dll *list, int i)
{
    node *ptr;
    node *ptr1;
    node *ptr2;
    ptr = list->root;
    int count = 0;

    if (get_size(list) == 1)
    {
        node *ptr;
        ptr = list->root;
        list->root = NULL;
        list->tail = NULL;
        free(ptr);
        return ;
    }

    if (i == 0)
    {
        node *x;
        x = list->root;
        list->root = list->root->next;
        list->root->prev = NULL;
        free(x);
        return;
    }

    if (i == get_size(list) - 1)
    {
        node *x;
        x = list->tail;
        list->tail = list->tail->prev;
        list->tail->next = NULL;
        free(x);
        return;
    }

    while (count != i - 1)
    {
        ptr = ptr->next;
        count++;
    }

    ptr1 = ptr->next;
    ptr2 = ptr1->next;

    ptr2->prev = ptr;
    ptr->next = ptr2;

    free(ptr1);
}

int find(my_dll *list, int x)
{
    node *ptr;
    ptr = list->root;
    int count = 0;

    while (ptr != NULL)
    {
        if (ptr->data == x)
        {
            return count;
        }
        ptr = ptr->next;
        count++;
    }
    return -1;
}

void prune(my_dll *list)
{
    int x = get_size(list) / 2;
    for (int i = 1; i <= x; i++)
    {
        delete (list, i);
    }
}

void print(my_dll *list)
{
    node *ptr;
    ptr = list->root;

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void print_reverse(my_dll *list)
{
    node *ptr;
    ptr = list->tail;

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}

int get_size(my_dll *list)
{
    node *ptr;
    ptr = list->root;
    int count = 0;

    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}