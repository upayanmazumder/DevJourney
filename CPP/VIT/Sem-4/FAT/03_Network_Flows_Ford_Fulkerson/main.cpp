#include <iostream>

using namespace std;

bool dfs(int u, int t, bool *visited, int *parent, int **residual, int n)
{
    visited[u] = true;
    if (u == t)
    {
        return true;
    }

    for (int v = 0; v < n; v++)
    {
        if (!visited[v] && residual[u][v] > 0)
        {
            parent[v] = u;
            if (dfs(v, t, visited, parent, residual, n))
            {
                return true;
            }
        }
    }

    return false;
}

int minValue(int a, int b)
{
    return (a < b) ? a : b;
}

int fordFulkerson(int **capacity, int n, int source, int sink)
{
    int **residual = new int *[n];
    for (int i = 0; i < n; i++)
    {
        residual[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            residual[i][j] = capacity[i][j];
        }
    }

    int *parent = new int[n];
    int maxFlow = 0;

    while (true)
    {
        bool *visited = new bool[n];
        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
            parent[i] = -1;
        }

        bool pathFound = dfs(source, sink, visited, parent, residual, n);
        delete[] visited;

        if (!pathFound)
        {
            break;
        }

        int pathFlow = 1000000000;
        int v = sink;

        while (v != source)
        {
            int u = parent[v];
            pathFlow = minValue(pathFlow, residual[u][v]);
            v = u;
        }

        v = sink;
        while (v != source)
        {
            int u = parent[v];
            residual[u][v] -= pathFlow;
            residual[v][u] += pathFlow;
            v = u;
        }

        maxFlow += pathFlow;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] residual[i];
    }
    delete[] residual;
    delete[] parent;

    return maxFlow;
}

int main()
{
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int **capacity = new int *[n];
    for (int i = 0; i < n; i++)
    {
        capacity[i] = new int[n];
    }

    cout << "Enter capacity matrix (" << n << " x " << n << "): \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> capacity[i][j];
        }
    }

    int source, sink;
    cout << "Enter source vertex (0 to " << n - 1 << "): ";
    cin >> source;
    cout << "Enter sink vertex (0 to " << n - 1 << "): ";
    cin >> sink;

    int result = fordFulkerson(capacity, n, source, sink);
    cout << "Maximum Flow = " << result << "\n";

    for (int i = 0; i < n; i++)
    {
        delete[] capacity[i];
    }
    delete[] capacity;

    return 0;
}
