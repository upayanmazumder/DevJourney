#include <stdio.h>
#include <ctype.h>   // for isalpha(), isdigit()
#include <string.h>  // for strlen()
#include <stdlib.h>  // for exit()

#define MAX 100

char stack[MAX];
int top = -1;

// Push element onto stack
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = c;
}

// Pop element from stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Peek top element of stack
char peek() {
    if (top == -1) return '\0';
    return stack[top];
}

// Function to check precedence of operators
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

// Function to check if operator is right-associative
int isRightAssociative(char op) {
    return op == '^';
}

// Convert infix to postfix
void infixToPostfix(char *infix) {
    char postfix[MAX];
    int i, k = 0;
    char ch;

    for (i = 0; i < strlen(infix); i++) {
        ch = infix[i];

        // If operand, add to postfix
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        // If '(', push to stack
        else if (ch == '(') {
            push(ch);
        }
        // If ')', pop until '('
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '(' from stack
        }
        // If operator
        else {
            while (top != -1 &&
                   ((precedence(peek()) > precedence(ch)) ||
                   (precedence(peek()) == precedence(ch) && !isRightAssociative(ch))) &&
                   peek() != '(') {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    // Pop all remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
    printf("%s\n", postfix);
}

int main() {
    char expr1[] = "a+b*(c^d-e)^(f+g*h)-i";
    char expr2[] = "(p+q)*(m-n)";

    printf("Infix: %s\nPostfix: ", expr1);
    infixToPostfix(expr1);

    printf("Infix: %s\nPostfix: ", expr2);
    infixToPostfix(expr2);

    return 0;
}
