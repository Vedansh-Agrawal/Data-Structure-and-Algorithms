#include <bits/stdc++.h>
using namespace std;

bool comp(int a, int b)
{
    return (a < b);
}

int main()
{
    long long int N;
    cin >> N;
    long long int phytele[N];
    long long int p[N];
    for (int i = 0; i < N; i++)
    {
        cin >> phytele[i];
        p[i] = phytele[i];
    }
    int r1[N - 1], r2[N - 1];
    long long int q[N];
    for (long long int i = 0; i < N; i++)
    {
        q[i] = 0;
    }
    for (long long int i = 0; i < N - 1; i++)
    {
        cin >> r1[i] >> r2[i];
    }
    for (long long int i = N - 2; i >= 0; i--)
    {
        if (r2[i] == 1) // i is not related to r1 all connections of i are related to r1
        {

            p[r1[i]] = max({p[r1[i]] + q[i + 1], p[i + 1] + q[r1[i]], p[r1[i]] + p[i + 1]}, comp);

            q[r1[i]] = q[r1[i]] + q[i + 1];
        }
        else if (r2[i] == 2) // i related to r1 and all connections of i too
        {
            p[r1[i]] = max(p[r1[i]] + q[i + 1], p[i + 1] + q[r1[i]]); // x is r1 y is i
            q[r1[i]] = q[r1[i]] + q[i + 1];
        }
        else // i to r1
        {
            other

                p[r1[i]] = p[r1[i]] + q[i + 1];
            q[r1[i]] = max(p[i + 1] + q[r1[i]], q[i + 1] + q[r1[i]]);
        }
    }
    cout << max(p[0], q[0]) << endl;
}