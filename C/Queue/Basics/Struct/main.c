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
    q->front = -1;
    q->rear = -1;
}

void insert(Queue *q, int item)
{
    if (q->rear + 1 == MAX)
    {
        printf("Overflow\n");
    }
    else
    {
        if (q->front == -1 && q->rear == -1)
        {
            q->front = 0;
            q->rear = 0;
        }
        else
        {
            q->rear = q->rear + 1;
        }
        q->data[q->rear] = item;
        printf("%d inserted\n", item);
    }
}

void delete(Queue *q)
{
    if (q->front == -1 || q->front > q->rear)
    {
        printf("Underflow\n");
    }
    else
    {
        int item = q->data[q->front];
        printf("%d deleted\n", item);
        q->front = q->front + 1;
        if (q->front > q->rear)
        {
            q->front = q->rear = -1; // reset after last deletion
        }
    }
}

void display(Queue *q)
{
    if (q->front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%d ", q->data[i]);
        }
        printf("\n");
    }
}

int main()
{
    Queue q;
    init(&q);

    insert(&q, 10);
    insert(&q, 20);
    insert(&q, 30);

    display(&q);

    delete(&q);
    delete(&q);

    display(&q);

    return 0;
}
