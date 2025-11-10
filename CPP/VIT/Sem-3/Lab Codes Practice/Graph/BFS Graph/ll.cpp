#include <iostream>
using namespace std;

constexpr int N = 5;

struct Node
{
    int vertex;
    Node *next;
};

struct Graph
{
    Node *adjList[N];
};

struct Queue
{
    int items[N];
    int front;
    int rear;
};

Node *createNode(int vertex)
{
    Node *newNode = new Node{vertex, nullptr};
    return newNode;
}

Graph createGraph()
{
    Graph graph{};
    for (int i = 0; i < N; ++i)
    {
        graph.adjList[i] = nullptr;
    }
    return graph;
}

void addEdge(Graph &graph, int src, int dest)
{
    Node *newNode = createNode(dest);
    newNode->next = graph.adjList[src];
    graph.adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph.adjList[dest];
    graph.adjList[dest] = newNode;
}

Queue createQueue()
{
    Queue q{};
    q.front = 0;
    q.rear = 0;
    return q;
}

void enqueue(Queue &q, int value)
{
    q.items[q.rear++] = value;
}

int dequeue(Queue &q)
{
    return q.items[q.front++];
}

bool isEmpty(const Queue &q)
{
    return q.front == q.rear;
}

void bfs(const Graph &graph, int start)
{
    int visited[N] = {0};
    Queue q = createQueue();
    visited[start] = 1;
    enqueue(q, start);
    while (!isEmpty(q))
    {
        int vertex = dequeue(q);
        cout << vertex << ' ';
        Node *temp = graph.adjList[vertex];
        while (temp)
        {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
    cout << '\n';
}

void freeGraph(Graph &graph)
{
    for (int i = 0; i < N; ++i)
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
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    cout << "BFS traversal starting from vertex 0:\n";
    bfs(graph, 0);

    freeGraph(graph);
    return 0;
}
