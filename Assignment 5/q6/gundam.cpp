#include <bits/stdc++.h>
using namespace std;
int N;

int main()
{
    cin >> N;
    vector<long long> P(N);
    vector<long long> Q(N, 0);
    vector<long long> A(N - 1);
    vector<long long> B(N - 1);
    long long ans = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> P[i];
    }
    for (int i = 0; i < N - 1; i++)
    {
        cin >> A[i];
        cin >> B[i];
    }
    for(int i = N - 2; i >= 0; i--)
    {
        int a, b;
        a = A[i];
        b = B[i];
        if (b == 0)
        {
            P[a] = P[a] + Q[i+1];
            Q[a] = max(P[i+1] + Q[a], Q[a] + Q[i+1]);
        }
        else if (b == 2)
        {
            P[a] = max(P[a] + Q[i+1], P[i+1] + Q[a]);
            Q[a] = Q[a] + Q[i+1];
        }
        else if (b == 1)
        {
            long long temp = max(P[a] + Q[i+1], P[i+1] + Q[a]);
            P[a] = max(temp, P[a] + P[i+1]);
            Q[a] = Q[a] + Q[i+1];
        }
    }
    ans = max(P[0], Q[0]);
    cout << ans << endl;
    return 0;
}