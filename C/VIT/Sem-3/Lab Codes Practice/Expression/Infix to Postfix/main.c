#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct
{
    char data[MAX];
    int top;
} Stack;

void push(Stack *stack, char value)
{
    stack->data[++stack->top] = value;
}

char pop(Stack *stack)
{

    return stack->data[stack->top--];
}

char peek(Stack *stack)
{
    return stack->data[stack->top];
}

int is_empty(Stack *stack)
{
    return stack->top == -1;
}

int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    if (c == '*' || c == '/' || c == '%')
    {
        return 2;
    }
    if (c == '+' || c == '-')
    {
        return 1;
    }
    return 0;
}

int is_operator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

int main(void)
{
    char infix[] = "A+(B*C-(D/E^F)*G)*H";
    char postfix[MAX];
    int index = 0;
    Stack stack;
    stack.top = -1;
    for (int i = 0; i < (int)strlen(infix); i++)
    {
        char c = infix[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        {
            postfix[index++] = c;
        }
        else if (c == '(')
        {
            push(&stack, c);
        }
        else if (c == ')')
        {
            while (!is_empty(&stack) && peek(&stack) != '(')
            {
                postfix[index++] = pop(&stack);
            }
            if (!is_empty(&stack) && peek(&stack) == '(')
            {
                pop(&stack);
            }
        }
        else if (is_operator(c))
        {
            while (!is_empty(&stack) && precedence(peek(&stack)) >= precedence(c))
            {
                postfix[index++] = pop(&stack);
            }
            push(&stack, c);
        }
    }
    while (!is_empty(&stack))
    {
        postfix[index++] = pop(&stack);
    }
    postfix[index] = '\0';
    printf("%s\n", postfix);
    return 0;
}
