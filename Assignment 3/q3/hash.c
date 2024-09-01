#include "hash.h"
#include <stdio.h>
#include <stdlib.h>

hashtable *init_hash_table(int a, int b, int countBucket)
{
    hashtable *temp = (hashtable *)malloc(sizeof(hashtable));
    temp->a = a;
    temp->b = b;
    temp->countBucket = countBucket;

    temp->buckets = (bucket *)malloc(sizeof(bucket) * countBucket);
    for (int i = 0; i < countBucket; i++)
    {
        (temp->buckets[i]).items = NULL;
    }
    return temp;
}
hashtable *insert(hashtable *T, int key)
{
    int x = ((T->a * key) + T->b) % T->countBucket;
    if (search(T, key))
    {
        item *ptr;
        for (ptr = (T->buckets[x]).items; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->key == key)
            {
                ptr->frequency++;
                return T;
            }
        }
    }

    else
    {
        item *temp = (item *)malloc(sizeof(item));
        temp->key = key;
        temp->frequency = 1;

        temp->next = (T->buckets[x]).items;
        (T->buckets[x]).items = temp;
        return T;
    }
}
int search(hashtable *T, int key)
{
    int x = ((T->a * key) + T->b) % T->countBucket;
    item *ptr;
    for (ptr = (T->buckets[x]).items; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->key == key)
        {
            return 1;
        }
    }

    if (ptr == NULL)
    {
        return 0;
    }
}
hashtable *Delete(hashtable *T, int key)
{
    if (search(T, key))
    {
        int x = ((T->a * key) + T->b) % T->countBucket;
        item *ptr;
        item *ptr1 = (T->buckets[x]).items;

        if (ptr1->key == key)
        {
            if (ptr1->frequency > 1)
            {
                ptr1->frequency--;
                return T;
            }
            else
            {
                (T->buckets[x]).items = ptr1->next;
                free(ptr1);
                return T;
            }
        }

        for (ptr = ptr1->next; ptr != NULL; ptr = ptr->next, ptr1 = ptr1->next)
        {
            if (ptr->key == key)
            {
                if (ptr->frequency > 1)
                {
                    ptr->frequency--;
                    return T;
                }
                else
                {
                    ptr1->next = ptr->next;
                    free(ptr);
                    return T;
                }
            }
        }
    }

    return T;
}
void print_table(hashtable *T)
{
    item *ptr;
    for (int i = 0; i < T->countBucket; i++)
    {
        for (ptr = (T->buckets[i]).items; ptr != NULL; ptr = ptr->next)
        {
            printf("%d %d ", ptr->key, ptr->frequency);
        }
        printf("\n");
    }
}