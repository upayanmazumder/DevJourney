#include <stdio.h>

int main() {
    int x, y, res;
    char mode, *m = &mode;
    int *a = &x, *b = &y, *c = &res;
    
    printf("Enter [num1] [operation] [num2]: ");
    scanf("%d %c %d", &x, &mode, &y);
    
    switch(*m) {
        case '+':
            res = x + y;
            break;
        case '-':
            res = x - y;
            break;
        case '*':
            res = x * y;
            break;
        case '/':
            res = x / y;
            break;
        default:
            break;
    }
    
    printf("%d %c %d = %d", x, mode, y, res);
}