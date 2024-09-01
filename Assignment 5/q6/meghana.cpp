#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long


int main()
{
    ll N;
    cin >> N;

    vector<ll> P(N);
    vector<ll> Q(N, 0);

    for(ll i = 0; i < N; i++)
    {
        cin >> P[i];
    }

    vector<ll> R1(N-1);
    vector<ll> R2(N-1);

    for(ll i = 0; i < N; i++)
    {
        cin >> R1[i] >> R2[i];
    }

    for(ll i = N - 2; i >= 0; i--)
    {
        ll r1, r2;
        r1 = R1[i];
        r2 = R2[i];

        if(r2 == 0)
        {
            ll p = P[i+1] + Q[r1];
            ll q = Q[i+1] + Q[r1];

            P[r1] = P[r1] + Q[i+1];
            Q[r1] = max(p, q);
        }
        else if (r2 == 1)
        {
            ll p1 = P[r1] + Q[i+1];
            ll p2 = P[i+1] + Q[r1];
            ll p3 = P[r1] + P[i+1];

            ll p = max(p1, p2);

            P[r1] = max(p, p3);
            Q[r1] = Q[r1] + Q[i+1];

        }
        else if(r2 == 2)
        {
            ll p1 = P[r1] + Q[i+1];
            ll p2 = P[i+1] + Q[r1];

            P[r1] = max(p1, p2);
            Q[r1] = Q[r1] + Q[i+1];
        }
    }

    ll Max = max(P[0], Q[0]);

    cout << Max << endl;
    return 0;
}