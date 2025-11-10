#include <iostream>
#include <string>

using namespace std;

bool isBalanced(const string &expr)
{
    char stack[100];
    int top = -1;
    for (char c : expr)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            stack[++top] = c;
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (top == -1)
            {
                return false;
            }
            char open = stack[top--];
            if ((c == ')' && open != '(') || (c == '}' && open != '{') || (c == ']' && open != '['))
            {
                return false;
            }
        }
    }
    return top == -1;
}

int main()
{
    string expr = "{[()]}";
    cout << (isBalanced(expr) ? "Balanced" : "Unbalanced") << '\n';
    return 0;
}
