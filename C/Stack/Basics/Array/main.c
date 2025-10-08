#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return top == MAX - 1;
}

void push(int val)
{
    if (isFull())
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = val;
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int peek()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

int main()
{
    push(10);
    push(20);
    push(30);

    printf("Top: %d\n", peek());         // 30
    printf("Pop: %d\n", pop());          // 30
    printf("Pop: %d\n", pop());          // 20
    printf("Is Empty: %d\n", isEmpty()); // 0 (false)
    printf("Pop: %d\n", pop());          // 10
    printf("Is Empty: %d\n", isEmpty()); // 1 (true)

    return 0;
}
