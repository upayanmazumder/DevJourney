#include <stdio.h>

#define N 5

void bfs(int graph[N][N], int start)
{
    int visited[N] = {0};
    int queue[N];
    int front = 0;
    int rear = 0;
    visited[start] = 1;
    queue[rear++] = start;
    while (front < rear)
    {
        int vertex = queue[front++];

        printf("%d ", vertex);
        for (int i = 0; i < N; i++)
        {
            if (graph[vertex][i] && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

int main(void)
{
    int graph[N][N] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}};
    bfs(graph, 0);
    return 0;
}
