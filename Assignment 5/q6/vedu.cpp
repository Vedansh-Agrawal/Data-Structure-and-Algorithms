#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    long long int N;
    scanf("%lld", &N);

    long long int arr[N];
    long long int arrs[N];

    for (long long int i = 0; i < N; i++)
    {
        scanf("%lld", &arr[i]);
        arrs[i] = 0;
    }

    long long int relation1[N - 1];
    long long int relation2[N - 1];

    for (long long int i = 0; i < N - 1; i++)
    {
        scanf("%lld", &relation1[i]);
        scanf("%lld", &relation2[i]);
    }

    for (long long int i = N - 2; i >= 0; i--)
    {

        if (relation2[i] == 1)
        {
            long long int x;
            if (arr[i + 1] + arrs[relation1[i]] < arr[relation1[i]] + arrs[i + 1])
                x = arr[relation1[i]] + arrs[i + 1];
            else
                x = arr[i + 1] + arrs[relation1[i]];
            if (x > arr[i + 1] + arr[relation1[i]])
                arr[relation1[i]] = x;
            else
                arr[relation1[i]] = arr[i + 1] + arr[relation1[i]];
            arrs[relation1[i]] += arrs[i + 1];
        }

        if (relation2[i] == 2)
        {
            if (arr[i + 1] + arrs[relation1[i]] < arr[relation1[i]] + arrs[i + 1])
                arr[relation1[i]] = arr[relation1[i]] + arrs[i + 1];
            else
                arr[relation1[i]] = arr[i + 1] + arrs[relation1[i]];
            arrs[relation1[i]] += arrs[i + 1];
        }

        if (relation2[i] == 0)
        {
            arr[relation1[i]] += arrs[i + 1];
            if (arr[i + 1] + arrs[relation1[i]] < arrs[relation1[i]] + arrs[i + 1])
                arrs[relation1[i]] = arrs[relation1[i]] + arrs[i + 1];
            else
                arrs[relation1[i]] = arr[i + 1] + arrs[relation1[i]];
        }
    }

    printf("%lld\n", max(arr[0], arrs[0]));
    return 0;
}