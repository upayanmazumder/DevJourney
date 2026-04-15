#include <iostream>

using namespace std;

const int MAX_V = 30;
const int INF = 1000000000;

int n;
int residual[MAX_V][MAX_V];
int parentArr[MAX_V];

bool bfs(int source, int sink)
{
    bool visited[MAX_V];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        parentArr[i] = -1;
    }

    int queue[MAX_V];
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
                parentArr[v] = u;
                visited[v] = true;

                if (v == sink)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

int minValue(int a, int b)
{
    return (a < b) ? a : b;
}

int edmondKarp(int capacity[][MAX_V], int source, int sink)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            residual[i][j] = capacity[i][j];
        }
    }

    int maxFlow = 0;

    while (bfs(source, sink))
    {
        int pathFlow = INF;

        int v = sink;
        while (v != source)
        {
            int u = parentArr[v];
            pathFlow = minValue(pathFlow, residual[u][v]);
            v = u;
        }

        v = sink;
        while (v != source)
        {
            int u = parentArr[v];
            residual[u][v] -= pathFlow;
            residual[v][u] += pathFlow;
            v = u;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main()
{
    cout << "Enter number of vertices: ";
    cin >> n;

    if (n <= 0 || n > MAX_V)
    {
        cout << "Invalid number of vertices. Max allowed is " << MAX_V << ".\n";
        return 0;
    }

    int capacity[MAX_V][MAX_V];

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

    int result = edmondKarp(capacity, source, sink);
    cout << "Maximum Flow = " << result << "\n";

    return 0;
}
