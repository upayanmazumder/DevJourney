#include <stdio.h>
#include <stdlib.h>

#define N 5


struct Node {
    int vertex;
    struct Node* next;
};


struct Graph {
    struct Node* adjList[N];
};


struct Queue {
    int items[N];
    int front;
    int rear;
};

struct Queue* createQueue() {
    struct Queue* q = malloc(sizeof(struct Queue));
    q->front = q->rear = 0;
    return q;
}

void enqueue(struct Queue* q, int value) {
    q->items[q->rear++] = value;
}

int dequeue(struct Queue* q) {
    return q->items[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}


struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}


struct Graph* createGraph() {
    struct Graph* graph = malloc(sizeof(struct Graph));
    for (int i = 0; i < N; i++)
        graph->adjList[i] = NULL;
    return graph;
}


void addEdge(struct Graph* graph, int src, int dest) {
    
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void bfs(struct Graph* graph, int start) {
    int visited[N] = {0};
    struct Queue* q = createQueue();

    visited[start] = 1;
    enqueue(q, start);

    while (!isEmpty(q)) {
        int vertex = dequeue(q);
        printf("%d ", vertex);

        struct Node* temp = graph->adjList[vertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    struct Graph* graph = createGraph();

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    printf("BFS traversal starting from vertex 0:\n");
    bfs(graph, 0);

    return 0;
}
