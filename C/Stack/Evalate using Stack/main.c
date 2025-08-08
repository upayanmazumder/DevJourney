#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} IntStack;

typedef struct {
    char data[MAX];
    int top;
} CharStack;

void initIntStack(IntStack *s) { s->top = -1; }
void initCharStack(CharStack *s) { s->top = -1; }

int isEmptyInt(IntStack *s) { return s->top == -1; }
int isEmptyChar(CharStack *s) { return s->top == -1; }

void pushInt(IntStack *s, int val) { s->data[++(s->top)] = val; }
void pushChar(CharStack *s, char val) { s->data[++(s->top)] = val; }

int popInt(IntStack *s) { return s->data[(s->top)--]; }
char popChar(CharStack *s) { return s->data[(s->top)--]; }

char peekChar(CharStack *s) { return s->data[s->top]; }

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int evaluatePostfix(char *expr) {
    IntStack s;
    initIntStack(&s);

    char *token = strtok(expr, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            pushInt(&s, atoi(token));
        } else {
            int val2 = popInt(&s);
            int val1 = popInt(&s);
            switch (token[0]) {
                case '+': pushInt(&s, val1 + val2); break;
                case '-': pushInt(&s, val1 - val2); break;
                case '*': pushInt(&s, val1 * val2); break;
                case '/': pushInt(&s, val1 / val2); break;
            }
        }
        token = strtok(NULL, " ");
    }
    return popInt(&s);
}

void infixToPostfix(char *infix, char *postfix) {
    CharStack s;
    initCharStack(&s);
    postfix[0] = '\0';

    char *token = strtok(infix, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            strcat(postfix, token);
            strcat(postfix, " ");
        }
        else if (token[0] == '(') {
            pushChar(&s, '(');
        }
        else if (token[0] == ')') {
            while (!isEmptyChar(&s) && peekChar(&s) != '(') {
                char op = popChar(&s);
                char temp[2] = {op, '\0'};
                strcat(postfix, temp);
                strcat(postfix, " ");
            }
            popChar(&s); // remove '('
        }
        else { // operator
            while (!isEmptyChar(&s) && precedence(peekChar(&s)) >= precedence(token[0])) {
                char op = popChar(&s);
                char temp[2] = {op, '\0'};
                strcat(postfix, temp);
                strcat(postfix, " ");
            }
            pushChar(&s, token[0]);
        }
        token = strtok(NULL, " ");
    }

    while (!isEmptyChar(&s)) {
        char op = popChar(&s);
        char temp[2] = {op, '\0'};
        strcat(postfix, temp);
        strcat(postfix, " ");
    }
}

int main() {
    // Case 1: Evaluate postfix
    char expr1[] = "2 1 + 3 *";
    printf("Postfix: %s\n", expr1);
    printf("Output: %d\n\n", evaluatePostfix(expr1));

    // Case 2: Infix to Postfix
    char expr2[] = "2 * ( 3 + 4 )";
    char postfix[MAX];
    infixToPostfix(expr2, postfix);
    printf("Infix to Postfix: %s\n", postfix);

    return 0;
}
