#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *front;
    Node *rear;
} Queue;

void enqueue(Queue *queue, int data)
{
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (!queue->rear)
    {
        queue->front = node;
        queue->rear = node;
        return;
    }
    queue->rear->next = node;
    queue->rear = node;
}

int dequeue(Queue *queue)
{
    if (!queue->front)
    {
        return -1;
    }
    Node *temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    if (!queue->front)
    {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

void display(Queue *queue)
{
    Node *current = queue->front;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(void)
{
    Queue queue = {NULL, NULL};
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    display(&queue);
    printf("%d\n", dequeue(&queue));
    display(&queue);
    while (queue.front)
    {
        dequeue(&queue);
    }
    return 0;
}
