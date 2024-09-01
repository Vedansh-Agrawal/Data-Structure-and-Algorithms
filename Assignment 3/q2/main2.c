#include <stdio.h>

unsigned long long int power(unsigned long long int x)
{
    unsigned long long int y = 1;
    for (int i = 0;i<x;i++)
    {
        y *= 2;
    }
    return y;
}

unsigned long long int number(unsigned long long int n)
{
    unsigned long long int i = 0;
    while (1)
    {
        if (n % 2 == 0)
        {
            i++;
            n = n / 2;
        }
        else
        {
            break;
        }
    }
    return i;
}

int main()
{
    unsigned long long int n;
    int t;
    scanf("%llu %d", &n, &t);

    for (int z = 0; z < t; z++)
    {
        unsigned long long int r;
        scanf("%llu", &r);

        unsigned long long int level;

        level = number(r);
        unsigned long long int a = power(level);

        char c = getchar();

        while ((c = getchar()) != '\n')
        {
            if (c == 'L')
            {
                if (r % 2 == 0)
                {
                    r -= (a/2);
                    level--;
                    a /= 2;
                }
            }

            else if (c == 'R')
            {
                if (r % 2 == 0)
                {
                    r += (a/2);
                    level--;
                    a /= 2;
                }
            }

            else if (c == 'U')
            {
                long long int x = (r - a) / (a*2);
                if (x % 2 == 0)
                {
                    if (r + a <= n)
                    {
                        r += a;
                        level++;
                        a *= 2;
                    }
                }

                else
                {
                    if (r - a <= n)
                    {
                        r -= a;
                        level++;
                        a *= 2;
                    }
                }
            }
        }

        printf("%llu\n",r);
    }
}