#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isFull()
{
    return (front == (rear + 1) % MAX);
}

int isEmpty()
{
    return front == -1;
}

void insert(int item)
{
    if (isFull())
    {
        printf("Overflow\n");
        return;
    }
    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = item;
    printf("%d inserted\n", item);
}

void delete()
{
    if (isEmpty())
    {
        printf("Underflow\n");
        return;
    }
    int item = queue[front];
    printf("%d deleted\n", item);
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    display();

    delete();
    delete();

    insert(60);
    insert(70);

    display();

    return 0;
}
