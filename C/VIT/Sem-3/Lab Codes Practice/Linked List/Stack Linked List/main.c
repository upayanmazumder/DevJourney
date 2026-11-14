#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void push(Stack *stack, int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
}

int pop(Stack *stack) {
    if (!stack->top) {
        return -1;
    }
    Node *temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

void display(Stack *stack) {
    Node *current = stack->top;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(void) {
    Stack stack = {NULL};
    push(&stack, 5);
    push(&stack, 10);
    push(&stack, 15);
    display(&stack);
    printf("%d\n", pop(&stack));
    display(&stack);
    while (stack.top) {
        pop(&stack);
    }
    return 0;
}
