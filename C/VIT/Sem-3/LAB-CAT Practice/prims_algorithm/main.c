#include <stdio.h>

#define V 5
#define INF 9999

int min_key(int key[], int mst_set[]) {
    int min = INF;
    int min_index = -1;
    for (int v = 0; v < V; v++) {
        if (!mst_set[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void prim(int graph[V][V]) {
    int parent[V];
    int key[V];
    int mst_set[V];
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mst_set[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++) {
        int u = min_key(key, mst_set);
        mst_set[u] = 1;
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mst_set[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    for (int i = 1; i < V; i++) {
        printf("%d - %d : %d\n", parent[i], i, graph[i][parent[i]]);
    }
}

int main(void) {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    prim(graph);
    return 0;
}
