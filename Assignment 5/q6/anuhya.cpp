#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    vector<long long int> arr1;
    vector<long long int> arr2;
    vector<long long int> arr3;
    vector<long long int> arr4;

    long long int temp;
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &temp);
        arr1.push_back(temp);
    }

    for (int i = 0; i < N; i++)
    {
        arr2.push_back(0);
    }
    // fill_n(arr2, N, 0);

    long long int flag = 0;
    for (long long int i = 0; i < 2 * N - 2; i++)
    {
        if (flag == 0)
        {
            scanf("%lld", &temp);
            arr3.push_back(temp);
            flag = 1;
        }
        else
        {
            scanf("%lld", &temp);
            arr4.push_back(temp);
            flag = 0;
        }
    }

    // for (long long int j = 0; j < N; ++j)
    // {
    //     printf("%lld ", arr1[j]);
    // }
    // printf("\n");

    // for (long long int j = 0; j < N; ++j)
    // {
    //     printf("%lld ", arr2[j]);
    // }
    // printf("\n");

    for (long long int i = N - 2; i >= 0; i--)
    {
        long long int max;
        if (arr4[i] == 1)
        {
            if ((arr1[arr3[i]] + arr2[i + 1]) > (arr1[i + 1] + arr2[arr3[i]]))
            {
                max = arr1[arr3[i]] + arr2[i + 1];
            }
            else
            {
                max = arr1[i + 1] + arr2[arr3[i]];
            }
            if (max < (arr1[arr3[i]] + arr1[i + 1]))
            {
                max = arr1[arr3[i]] + arr1[i + 1];
            }
            arr1[arr3[i]] = max;

            arr2[arr3[i]] = arr2[arr3[i]] + arr2[i + 1];

            // printf("%lld\n", max);
            // printf("%lld\n", arr2[arr3[i]]);
        }
        else if (arr4[i] == 2)
        {
            // p[r1[i]] = max(p[r1[i]] + q[i + 1], p[i + 1] + q[r1[i]]); // x is r1 y is i
            // q[r1[i]] = q[r1[i]] + q[i + 1];
            if ((arr1[arr3[i]] + arr2[i + 1]) > (arr1[i + 1] + arr2[arr3[i]]))
            {
                max = arr1[arr3[i]] + arr2[i + 1];
            }
            else
            {
                max = arr1[i + 1] + arr2[arr3[i]];
            }
            arr1[arr3[i]] = max;

            arr2[arr3[i]] = arr2[arr3[i]] + arr2[i + 1];
        }
        else if (arr4[i] == 0)
        {
            arr1[arr3[i]] = arr1[arr3[i]] + arr2[i + 1];
            if ((arr1[i + 1] + arr2[arr3[i]]) + (arr2[i + 1] + arr2[arr3[i]]))
            {
                max = arr1[i + 1] + arr2[arr3[i]];
            }
            arr2[arr3[i]] = max;
        }
    }

    if (arr1[0] > arr2[0])
    {
        printf("%lld", arr1[0]);
    }
    else
    {
        printf("%lld", arr2[0]);
    }
}