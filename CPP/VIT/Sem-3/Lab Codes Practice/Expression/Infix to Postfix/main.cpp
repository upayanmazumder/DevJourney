#include <iostream>
#include <string>

using namespace std;

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

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

string toPostfix(const string &infix)
{
    string postfix;
    char stack[100];
    int top = -1;
    for (char c : infix)
    {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        {
            postfix.push_back(c);
        }
        else if (c == '(')
        {
            stack[++top] = c;
        }
        else if (c == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix.push_back(stack[top--]);
            }
            if (top != -1 && stack[top] == '(')
            {
                --top;
            }
        }
        else if (isOperator(c))
        {
            while (top != -1 && precedence(stack[top]) >= precedence(c))
            {
                postfix.push_back(stack[top--]);
            }
            stack[++top] = c;
        }
    }
    while (top != -1)
    {
        postfix.push_back(stack[top--]);
    }
    return postfix;
}

int main()
{
    string infix = "A+(B*C-(D/E^F)*G)*H";
    cout << toPostfix(infix) << '\n';
    return 0;
}
