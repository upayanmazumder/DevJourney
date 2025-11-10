#include <iostream>
#include <string>

using namespace std;

int evaluatePostfix(const string &expr)
{
    int stack[100];
    int top = -1;
    for (char c : expr)
    {
        if (c >= '0' && c <= '9')
        {
            stack[++top] = c - '0';
        }
        else
        {
            int b = stack[top--];
            int a = stack[top--];
            int result = 0;
            switch (c)
            {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / b;
                break;
            case '%':
                result = a % b;
                break;
            default:
                result = 0;
                break;
            }
            stack[++top] = result;
        }
    }
    return stack[top];
}

int main()
{
    string expr = "231*+9-";
    cout << evaluatePostfix(expr) << '\n';
    return 0;
}
