#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N;
    cin >> N;

    vector<long long> p(N);
    for(int i = 0; i < N; i++)
    {
        long long h;
        cin >> h;
        p[i] = h;
    }

    vector<pair<long long, int>> connection(N-1);
    for(int i = 0; i < N-1; i++)
    {
        long long a;
        int b;
        cin >> a >> b;
        connection[i] = make_pair(a, b);
    }

    vector<long long> q(N);
    q.assign(N, 0);

    for(int i = N-2; i >= 0; i--)
    {
        if(connection[i].second == 0)
        {
            p[connection[i].first] += q[i+1];
            q[connection[i].first] = max(p[i+1]+q[connection[i].first], q[i+1]+q[connection[i].first]);
        }
        else
        {
            if(connection[i].second == 2)
            {
                p[connection[i].first] = max(p[connection[i].first]+q[i+1], p[i+1]+q[connection[i].first]);
            }
            else if(connection[i].second == 1)
            {
                p[connection[i].first] = max(p[connection[i].first]+q[i+1], p[connection[i].first]+p[i+1]);
                p[connection[i].first] = max(p[connection[i].first], p[i+1]+q[connection[i].first]);
            }
            q[connection[i].first] += q[i+1];
        }
    }

    long long ans = max(p[0], q[0]);
    cout << ans << endl;
}