#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "complex.h"

complex *createcomplex(int N)
{
    complex *head;
    head = NULL;

    for (int i = 0;i<N;i++)
    {
        complex *a;
        a = (complex *)malloc(sizeof(complex));
        scanf("%lf",&a->x);
        if (head == NULL)
        {
            a->pointer = NULL;
            a->bpointer = NULL;
            head = a;
        }
        else
        {
            head->bpointer = a;
            a->bpointer = NULL;
            a->pointer = head;
            head = a;
        }
    }
    return head;
}

void printcomplex(complex *a)
{
    complex *ptr;
    complex *ptr1;

    ptr = a;
    ptr1 = ptr->pointer;

    while (ptr1 != NULL)
    {
        ptr = ptr->pointer;
        ptr1 = ptr1->pointer;
    }

    while(ptr != NULL)
    {
        printf("%.2lf ",ptr->x);
        ptr = ptr->bpointer;
    }
    printf("\n");
}

int main()
{
    char key[4];
    int N;

    scanf("%s",key);
    scanf("%d",&N);

    if (strcmp(key,"ADD") == 0)
    {
        complex *a;
        complex *b;
        a = createcomplex(N);
        b = createcomplex(N);
        add(a,b);
        printcomplex(a);
    }

    else if (strcmp(key,"SUB") == 0)
    {
        complex *a;
        complex *b;
        a = createcomplex(N);
        b = createcomplex(N);
        sub(a,b);
        printcomplex(a);
    }

    else if (strcmp(key,"DOT") == 0)
    {
        complex *a;
        complex *b;
        a = createcomplex(N);
        b = createcomplex(N);
        printf("%.2lf\n",dot(a,b));
    }

    else if (strcmp(key,"COS") == 0)
    {
        complex *a;
        complex *b;
        a = createcomplex(N);
        b = createcomplex(N);
        printf("%.2lf\n",COS(a,b));
    }

    else if (strcmp(key,"MOD") == 0)
    {
        complex *a;
        a = createcomplex(N);
        printf("%.2lf\n",mod(a));
    }
}