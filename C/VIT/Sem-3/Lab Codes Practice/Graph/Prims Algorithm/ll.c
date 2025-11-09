#include <stdio.h>
#include <stdlib.h>

#define V 5
#define INF 9999

struct Node
{
    int vertex;
    int weight;
    struct Node *next;
};

struct Graph
{
    struct Node *adjList[V];
};

struct Node *createNode(int vertex, int weight)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph()
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    for (int i = 0; i < V; i++)
        graph->adjList[i] = NULL;
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest, int weight)
{

    struct Node *newNode = createNode(dest, weight);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src, weight);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

int minKey(int key[], int mstSet[])
{
    int min = INF, minIndex = -1;
    for (int v = 0; v < V; v++)
    {
        if (!mstSet[v] && key[v] < min)
        {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void prim(struct Graph *graph)
{
    int parent[V];
    int key[V];
    int mstSet[V];

    for (int i = 0; i < V; i++)
    {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;

        struct Node *temp = graph->adjList[u];
        while (temp)
        {
            int v = temp->vertex;
            int w = temp->weight;

            if (!mstSet[v] && w < key[v])
            {
                key[v] = w;
                parent[v] = u;
            }
            temp = temp->next;
        }
    }

    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d\n", parent[i], i, key[i]);
}

int main()
{
    struct Graph *graph = createGraph();

    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 6);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 8);
    addEdge(graph, 1, 4, 5);
    addEdge(graph, 2, 4, 7);
    addEdge(graph, 3, 4, 9);

    prim(graph);

    return 0;
}
