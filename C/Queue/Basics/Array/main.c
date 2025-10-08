#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = 0;
int rear = -1;

int isEmpty()
{
    return front > rear;
}

int isFull()
{
    return rear == MAX - 1;
}

void enqueue(int val)
{
    if (isFull())
    {
        printf("Queue Overflow\n");
        return;
    }
    queue[++rear] = val;
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

int peek()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return -1;
    }
    return queue[front];
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Front: %d\n", peek());       // 10
    printf("Dequeue: %d\n", dequeue());  // 10
    printf("Dequeue: %d\n", dequeue());  // 20
    printf("Is Empty: %d\n", isEmpty()); // 0 (false)
    printf("Dequeue: %d\n", dequeue());  // 30
    printf("Is Empty: %d\n", isEmpty()); // 1 (true)

    return 0;
}
