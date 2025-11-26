#include <stdio.h>

int main(void)
{
    char expr[] = "231*+9-";
    int stack[100];
    int top = -1;
    for (int i = 0; expr[i] != '\0'; i++)
    {
        char c = expr[i];
        if (c >= '0' && c <= '9')
        {
            stack[++top] = c - '0';
        }
        else
        {
            int b = stack[top--];
            int a = stack[top--];
            int result = 0;
            if (c == '+')
            {
                result = a + b;
            }
            else if (c == '-')
            {
                result = a - b;
            }
            else if (c == '*')
            {
                result = a * b;
            }
            else if (c == '/')
            {
                result = a / b;
            }
            else if (c == '%')
            {
                result = a % b;
            }
            stack[++top] = result;
        }
    }
    printf("%d\n", stack[top]);
    return 0;
}
