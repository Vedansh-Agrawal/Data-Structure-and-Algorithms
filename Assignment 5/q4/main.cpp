#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void makegraph(vector<pair<long long int, long long int>> arr[], long long int u, long long int v, long long int w)
{
    arr[u].push_back(make_pair(v, w));
    arr[v].push_back(make_pair(u, w));
}

void dijkstra(vector<pair<long long int, long long int>> arr[], long long int ans[])
{
    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> heap;
    ans[0] = 0;

    heap.push(make_pair(0, 0));

    while (!heap.empty())
    {
        long long int x = heap.top().second;
        heap.pop();

        for (auto y : arr[x])
        {
            long long int node = y.first;
            long long int weight = y.second;

            if (ans[node] > ans[x] + weight)
            {
                ans[node] = ans[x] + weight;
                heap.push(make_pair(ans[node], node));
            }
        }
    }
}

int main()
{
    long long int n, m, k;
    scanf("%lld %lld %lld", &n, &m, &k);

    vector<pair<long long int, long long int>> graph[n + 1];
    long long int mess[n + 1];
    long long int ans[n + 1];

    for (long long int i = 0; i < n + 1; i++)
    {
        ans[i] = LONG_LONG_MAX;
        mess[i] = 0;
    }

    for (long long int i = 0; i < k; i++)
    {
        long long int x;
        scanf("%lld", &x);
        mess[x] = 1;
    }

    for (long long int i = 0; i < m; i++)
    {
        long long int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);

        if (mess[u] == 1)
        {
            u = 0;
        }

        if (mess[v] == 1)
        {
            v = 0;
        }

        if (u != v)
        {
            makegraph(graph, u, v, w);
        }
    }

    dijkstra(graph, ans);

    for (long long int i = 1; i < n + 1; i++)
    {
        if (ans[i] == LONG_LONG_MAX)
        {
            printf("0 ");
        }
        else
        {
            printf("%lld ", ans[i]);
        }
    }

    return 0;
}