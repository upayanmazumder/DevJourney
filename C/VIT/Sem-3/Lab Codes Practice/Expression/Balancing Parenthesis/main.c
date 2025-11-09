#include <stdio.h>

int main(void) {
    char expr[] = "{[()]}";
    char stack[100];
    int top = -1;
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } else if (c == ')' || c == '}' || c == ']') {
            if (top == -1) {
                printf("Unbalanced\n");
                return 0;
            }
            char s = stack[top--];
            if ((c == ')' && s != '(') || (c == '}' && s != '{') || (c == ']' && s != '[')) {
                printf("Unbalanced\n");
                return 0;
            }
        }
    }
    if (top == -1) {
        printf("Balanced\n");
    } else {
        printf("Unbalanced\n");
    }
    return 0;
}
