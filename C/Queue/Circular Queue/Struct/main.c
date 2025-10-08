#include <stdio.h>
#define MAX 5

typedef struct
{
    int data[MAX];
    int front;
    int rear;
} CircularQueue;

void init(CircularQueue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isFull(CircularQueue *q)
{
    return (q->front == (q->rear + 1) % MAX);
}

int isEmpty(CircularQueue *q)
{
    return q->front == -1;
}

void insert(CircularQueue *q, int item)
{
    if (isFull(q))
    {
        printf("Overflow\n");
        return;
    }
    if (isEmpty(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear = (q->rear + 1) % MAX;
    }
    q->data[q->rear] = item;
    printf("%d inserted\n", item);
}

void delete(CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf("Underflow\n");
        return;
    }
    int item = q->data[q->front];
    printf("%d deleted\n", item);
    if (q->front == q->rear)
    {
        // last element removed, reset queue
        q->front = q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % MAX;
    }
}

void display(CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (1)
    {
        printf("%d ", q->data[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    CircularQueue q;
    init(&q);

    insert(&q, 10);
    insert(&q, 20);
    insert(&q, 30);
    insert(&q, 40);
    insert(&q, 50); // queue full now

    display(&q);

    delete(&q);
    delete(&q);

    insert(&q, 60);
    insert(&q, 70);

    display(&q);

    return 0;
}
