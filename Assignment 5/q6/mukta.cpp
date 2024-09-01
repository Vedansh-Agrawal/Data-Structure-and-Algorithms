#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    ll n;
    cin >> n;

    ll p[n];
    for(ll i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        p[i] = temp;
    }

    ll q[n];
    for(int i = 0; i < n; i++) {
        q[i] = 0;
    }
    ll parent[n-1];
    ll connection[n-1];

    for(ll i = 0; i < n-1; i++) {
        ll temp1, temp2;
        cin >> temp1 >> temp2;
        parent[i] = temp1;
        connection[i] = temp2;
    }

    ll vertice = n-1;

    for(ll i = n-2; i >= 0; i--) {
        if(connection[i] == 0) {
            p[parent[i]] = p[parent[i]] + q[vertice];
            ll a = p[vertice] + q[parent[i]];
            ll b = q[parent[i]] + q[vertice];
            q[parent[i]] = max(a, b);
        }

        else if(connection[i] == 1) {
            ll a = p[parent[i]] + q[vertice];
            ll b = p[vertice] + q[parent[i]];
            ll c = p[parent[i]] + p[vertice];
            ll temp = max(a, b);
            p[parent[i]] = max(temp, c);
            q[parent[i]] = q[parent[i]] + q[vertice];
        }

        else if(connection[i] == 2) {
            ll a = p[parent[i]] + q[vertice];
            ll b = p[vertice] + q[parent[i]];
            p[parent[i]] = max(a, b);
            q[parent[i]] = q[parent[i]] + q[vertice];
        }

        vertice--;
    }

    ll ans = max(p[0], q[0]);
    printf("%lld\n", ans);
}