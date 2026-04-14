#include <iostream>

using namespace std;

bool bfs(int **residual, int n, int source, int sink, int *parent)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        parent[i] = -1;
    }

    int *queue = new int[n];
    int front = 0;
    int rear = 0;

    queue[rear++] = source;
    visited[source] = true;

    while (front < rear)
    {
        int u = queue[front++];

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && residual[u][v] > 0)
            {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = true;

                if (v == sink)
                {
                    delete[] visited;
                    delete[] queue;
                    return true;
                }
            }
        }
    }

    delete[] visited;
    delete[] queue;
    return false;
}

int minValue(int a, int b)
{
    return (a < b) ? a : b;
}

int edmondKarp(int **capacity, int n, int source, int sink)
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

    while (bfs(residual, n, source, sink, parent))
    {
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

    int result = edmondKarp(capacity, n, source, sink);
    cout << "Maximum Flow = " << result << "\n";

    for (int i = 0; i < n; i++)
    {
        delete[] capacity[i];
    }
    delete[] capacity;

    return 0;
}
