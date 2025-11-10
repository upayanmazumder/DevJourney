#include <iostream>

using namespace std;

constexpr int V = 5;
constexpr int INF = 9999;

int minKey(const int key[V], const int mstSet[V])
{
    int min = INF;
    int minIndex = -1;
    for (int v = 0; v < V; ++v)
    {
        if (!mstSet[v] && key[v] < min)
        {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void prim(const int graph[V][V])
{
    int parent[V];
    int key[V];
    int mstSet[V];

    for (int i = 0; i < V; ++i)
    {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; ++count)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;
        for (int v = 0; v < V; ++v)
        {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    for (int i = 1; i < V; ++i)
    {
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << '\n';
    }
}

int main()
{
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};
    prim(graph);
    return 0;
}
