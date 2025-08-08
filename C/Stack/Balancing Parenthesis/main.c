#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, char val) {
    if (isFull(s)) {
        printf("Stack is full\n");
        return;
    }
    s->data[++(s->top)] = val;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->data[(s->top)--];
}

char peek(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->data[s->top];
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isBalanced(char *expr) {
    Stack s;
    init(&s);

    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        } 
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&s) || !isMatchingPair(pop(&s), ch)) {
                return 0;
            }
        }
    }

    return isEmpty(&s);
}

int main() {
    char input[MAX];

    printf("Enter expression: ");
    scanf("%s", input);

    if (isBalanced(input)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
