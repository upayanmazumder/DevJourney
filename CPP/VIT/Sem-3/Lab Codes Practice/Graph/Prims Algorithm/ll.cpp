#include <iostream>

using namespace std;

constexpr int V = 5;
constexpr int INF = 9999;

struct Node
{
    int vertex;
    int weight;
    Node *next;
};

struct Graph
{
    Node *adjList[V];
};

Node *createNode(int vertex, int weight)
{
    Node *newNode = new Node{vertex, weight, nullptr};
    return newNode;
}

Graph createGraph()
{
    Graph graph{};
    for (int i = 0; i < V; ++i)
    {
        graph.adjList[i] = nullptr;
    }
    return graph;
}

void addEdge(Graph &graph, int src, int dest, int weight)
{
    Node *newNode = createNode(dest, weight);
    newNode->next = graph.adjList[src];
    graph.adjList[src] = newNode;

    newNode = createNode(src, weight);
    newNode->next = graph.adjList[dest];
    graph.adjList[dest] = newNode;
}

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

void prim(const Graph &graph)
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

        Node *temp = graph.adjList[u];
        while (temp)
        {
            int v = temp->vertex;
            int weight = temp->weight;
            if (!mstSet[v] && weight < key[v])
            {
                key[v] = weight;
                parent[v] = u;
            }
            temp = temp->next;
        }
    }

    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; ++i)
    {
        cout << parent[i] << " - " << i << " \t" << key[i] << '\n';
    }
}

void freeGraph(Graph &graph)
{
    for (int i = 0; i < V; ++i)
    {
        Node *current = graph.adjList[i];
        while (current)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        graph.adjList[i] = nullptr;
    }
}

int main()
{
    Graph graph = createGraph();

    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 6);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 8);
    addEdge(graph, 1, 4, 5);
    addEdge(graph, 2, 4, 7);
    addEdge(graph, 3, 4, 9);

    prim(graph);

    freeGraph(graph);
    return 0;
}
