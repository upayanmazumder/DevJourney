#include <iostream>

using namespace std;

const int MAX_V = 30;
const int INF = 1000000000;

int n;
int residual[MAX_V][MAX_V];
int parentArr[MAX_V];
bool visited[MAX_V];

bool dfs(int u, int sink)
{
    visited[u] = true;

    if (u == sink)
    {
        return true;
    }

    for (int v = 0; v < n; v++)
    {
        if (visited[v] == false && residual[u][v] > 0)
        {
            parentArr[v] = u;
            if (dfs(v, sink))
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

int fordFulkerson(int capacity[][MAX_V], int source, int sink)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            residual[i][j] = capacity[i][j];
        }
    }

    int maxFlow = 0;

    while (true)
    {
        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
            parentArr[i] = -1;
        }

        bool pathFound = dfs(source, sink);

        if (!pathFound)
        {
            break;
        }

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

    int result = fordFulkerson(capacity, source, sink);
    cout << "Maximum Flow = " << result << "\n";

    return 0;
}
