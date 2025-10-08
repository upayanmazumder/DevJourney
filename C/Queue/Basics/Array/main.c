#include <stdio.h>
#define MAX 100

void insert(int queue[], int max, int *front, int *rear, int item)
{
    if (*rear + 1 == max)
    {
        printf("Overflow\n");
    }
    else
    {
        if (*front == -1 && *rear == -1)
        {
            *front = 0;
            *rear = 0;
        }
        else
        {
            *rear = *rear + 1;
        }
        queue[*rear] = item;
        printf("%d inserted\n", item);
    }
}

void delete(int queue[], int *front, int *rear)
{
    if (*front == -1 || *front > *rear)
    {
        printf("Underflow\n");
    }
    else
    {
        int item = queue[*front];
        printf("%d deleted\n", item);
        *front = *front + 1;
        if (*front > *rear)
        {
            *front = *rear = -1; // reset after last deletion
        }
    }
}

void display(int queue[], int front, int rear)
{
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int queue[MAX];
    int front = -1, rear = -1;

    insert(queue, MAX, &front, &rear, 10);
    insert(queue, MAX, &front, &rear, 20);
    insert(queue, MAX, &front, &rear, 30);

    display(queue, front, rear);

    delete(queue, &front, &rear);
    delete(queue, &front, &rear);

    display(queue, front, rear);

    return 0;
}
