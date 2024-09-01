#include <stdio.h>
#include "complex.h"
#include <math.h>

void add(complex *a, complex *b)
{
    complex *ptr;
    complex *ptr1;
    ptr = a;
    ptr1 = b;

    while (ptr1 != NULL)
    {
        ptr->x += ptr1->x;
        ptr = ptr->pointer;
        ptr1 = ptr1->pointer;
    }
}

void sub(complex *a, complex *b)
{
    complex *ptr;
    complex *ptr1;
    ptr = a;
    ptr1 = b;

    while (ptr != NULL)
    {
        ptr->x -= ptr1->x;
        ptr = ptr->pointer;
        ptr1 = ptr1->pointer;
    }
}

double mod(complex *a)
{
    double y = 0;
    complex *ptr;
    ptr = a;

    while(ptr != NULL)
    {
        y += ptr->x*ptr->x;
        ptr = ptr->pointer;
    }
    y = sqrt(y);
    return y;
}

double dot(complex *a, complex *b)
{
    complex *ptr;
    complex *ptr1;
    ptr = a;
    ptr1 = b;

    double y = 0;
    while (ptr != NULL)
    {
        y += ptr1->x*ptr->x;
        ptr = ptr->pointer;
        ptr1 = ptr1->pointer;
    }
    return y;
}

double COS(complex *a, complex *b)
{
    double y;
    y = dot(a,b)/(mod(a)*mod(b));
    return y;
}

