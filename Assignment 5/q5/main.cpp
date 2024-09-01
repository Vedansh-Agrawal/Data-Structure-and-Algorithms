#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void makegraph(vector<pair<long long int, long long int>> arr[], long long int u, long long int v, long long int w)
{
    arr[u].push_back(make_pair(v, w));
    arr[v].push_back(make_pair(u, w));
}

void prim(vector<pair<long long int, long long int>> arr[], long long int ans[], long long int n)
{
    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> heap;

    long long int dist[n];
    long long int boo[n];

    for (long long int i = 0; i < n; i++)
    {
        ans[i] = -1;
        dist[i] = LONG_LONG_MAX;
        boo[i] = 0;
    }

    dist[0] = 0;

    heap.push(make_pair(0, 0));

    while (!heap.empty())
    {
        long long int x = heap.top().second;
        heap.pop();

        if (boo[x] == 1)
        {
            continue;
        }

        boo[x] = 1;

        for (auto y : arr[x])
        {
            long long int node = y.first;
            long long int weight = y.second;

            if (boo[node] == 0 && dist[node] > weight)
            {
                dist[node] = weight;
                heap.push(make_pair(dist[node], node));
                ans[node] = x;
            }
        }
    }
}

bool compx(pair<long long int, pair<long long int, long long int>> x1, pair<long long int, pair<long long int, long long int>> x2)
{
    return (x1.second.first < x2.second.first);
}

bool compy(pair<long long int, pair<long long int, long long int>> x1, pair<long long int, pair<long long int, long long int>> x2)
{
    return (x1.second.second < x2.second.second);
}

long long int min(pair<long long int, pair<long long int, long long int>> x1, pair<long long int, pair<long long int, long long int>> x2)
{
    long long int x = x1.second.first - x2.second.first;
    long long int y = x1.second.second - x2.second.second;

    if (x < 0)
        x = -x;
    if (y < 0)
        y = -y;

    if (x < y)
        return x;
    return y;
}

int main()
{

    long long int N;
    scanf("%lld", &N);

    vector<pair<long long int, long long int>> graph[N];

    vector<pair<long long int, pair<long long int, long long int>>> node;

    for (long long int i = 0; i < N; i++)
    {
        long long int x, y;
        scanf("%lld %lld", &x, &y);

        node.push_back(make_pair(i, make_pair(x, y)));
    }

    sort(node.begin(), node.end(), compx);

    for (long long int i = 0; i < N - 1; i++)
    {
        makegraph(graph, node[i].first, node[i + 1].first, min(node[i], node[i + 1]));
    }

    sort(node.begin(), node.end(), compy);

    for (long long int i = 0; i < N - 1; i++)
    {
        makegraph(graph, node[i].first, node[i + 1].first, min(node[i], node[i + 1]));
    }

    long long int ans[N];
    prim(graph, ans, N);

    long long int answer = 0;
    for (long long int i = 1; i < N; i++)
    {
        for (auto x : graph[i])
        {
            if (x.first == ans[i])
            {
                answer += x.second;
                break;
            }
        }
    }

    printf("%lld\n", answer);
}