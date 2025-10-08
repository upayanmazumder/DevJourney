#include <stdio.h>
#define MAX 100

typedef struct
{
    int data[MAX];
    int top;
} Stack;

void init(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return s->top == MAX - 1;
}

void push(Stack *s, int val)
{
    if (isFull(s))
    {
        printf("Stack Overflow\n");
        return;
    }
    s->data[++(s->top)] = val;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->data[(s->top)--];
}

int peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return s->data[s->top];
}

int main()
{
    Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top: %d\n", peek(&s));         // 30
    printf("Pop: %d\n", pop(&s));          // 30
    printf("Pop: %d\n", pop(&s));          // 20
    printf("Is Empty: %d\n", isEmpty(&s)); // 0 (false)
    printf("Pop: %d\n", pop(&s));          // 10
    printf("Is Empty: %d\n", isEmpty(&s)); // 1 (true)

    return 0;
}
