#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct Complex
{
    double x;
    struct Complex *pointer;
    struct Complex *bpointer;
} complex;

void add(complex *a,complex *b);
void sub(complex *a,complex *b);
double mod(complex *a);
double dot(complex *a,complex *b);
double COS(complex *a,complex *b);

#endif