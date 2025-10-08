#include <stdio.h>
#define MAX 100

typedef struct
{
    int data[MAX];
    int front;
    int rear;
} Queue;

void init(Queue *q)
{
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue *q)
{
    return q->front > q->rear;
}

int isFull(Queue *q)
{
    return q->rear == MAX - 1;
}

void enqueue(Queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue Overflow\n");
        return;
    }
    q->data[++(q->rear)] = val;
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow\n");
        return -1;
    }
    return q->data[(q->front)++];
}

int peek(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return q->data[q->front];
}

int main()
{
    Queue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Front: %d\n", peek(&q));       // 10
    printf("Dequeue: %d\n", dequeue(&q));  // 10
    printf("Dequeue: %d\n", dequeue(&q));  // 20
    printf("Is Empty: %d\n", isEmpty(&q)); // 0 (false)
    printf("Dequeue: %d\n", dequeue(&q));  // 30
    printf("Is Empty: %d\n", isEmpty(&q)); // 1 (true)

    return 0;
}
