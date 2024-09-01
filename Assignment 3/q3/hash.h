#ifndef HASH_H
#define HASH_H

int numinsert[4], numsearch[4], totali , totals, j;

typedef struct Item
{
    int key;
    int frequency;
    struct Item *next;
} item;

typedef struct Bucket
{
    struct Item *items;
} bucket;

typedef struct HashTable
{
    int a, b, countBucket;
    struct Bucket *buckets;
} hashtable;

hashtable *init_hash_table(int a, int b, int countBuckets);
hashtable *insert(hashtable *T, int key);
int search(hashtable *T, int key);
hashtable *Delete(hashtable *T,int key);
void print_table();

#endif