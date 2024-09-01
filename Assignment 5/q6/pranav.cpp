#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
    // Taking inputs

    long long int N;
    scanf("%lld", &N);

    vector<long long int> array1;
    vector<long long int> array2;
    vector<long long int> array3;
    vector<long long int> array4;

    for (long long int i = 0; i < N; ++i)
    {
        long long int inp;
        scanf("%lld", &inp);
        array1.push_back(inp);
    }

    for (long long int i = 0; i < N; ++i)
    {
        array2.push_back(0);
    }

    int check1 = 1;

    for (long long int i = 0; i < 2 * (N - 1); ++i)
    {
        long long int inp;
        scanf("%lld", &inp);

        if (check1 == 1)
        {
            array3.push_back(inp);
            check1 = 0;
        }
        else if (check1 == 0)
        {
            array4.push_back(inp);
            check1 = 1;
        }
    }

    // for (long long int j = 0; j < N; ++j)
    // {
    //     printf("%lld ", array1[j]);
    // }
    // printf("\n");

    // for (long long int j = 0; j < N; ++j)
    // {
    //     printf("%lld ", array2[j]);
    // }
    // printf("\n");

    // for (long long int j = 0; j < N-1; ++j)
    // {
    //     printf("%lld ", array3[j]);
    // }
    // printf("\n");

    // for (long long int j = 0; j < N-1; ++j)
    // {
    //     printf("%lld ", array4[j]);
    // }
    // printf("\n");

    long long int p, q, r, s;

    // Computing the answer

    for (long long int i = N - 2; i > -1; --i)
    {
        long long int a = array3[i];
        long long int b = array4[i];

        if (b == 0)
        {
            long long int t1 = array1[i + 1] + array2[a];
            long long int t2 = array2[i + 1] + array2[a];
            array1[a] += array2[i + 1];
            array2[a] = max(t1,t2);
        }
        else if (b != 0)
        {
            if (b != 1)
            {
                long long t1 = array1[a] + array2[i + 1];
                long long t2 = array1[i + 1] + array2[a];
                array1[a] = max(t1, t2);
                array2[a] += array2[i + 1];
            }

            else if (b == 1)
            {
                p = array1[a] + array2[i + 1];
                q = array1[i + 1] + array2[a];
                r = array1[a] + array1[i + 1];
                array1[a] = max(max(r, q), p);
                array2[a] += array2[i + 1];
            }
        }
        // for (long long int j = 0; j < N; ++j)
        // {
        //     printf("%lld ", array1[j]);
        // }
        // printf("\n");

        // for (long long int j = 0; j < N; ++j)
        // {
        //     printf("%lld ", array1[j]);
        // }
        // printf("\n");
    }

    s = max(array1[0], array2[0]);
    printf("%lld\n", s);

    return 0;
}