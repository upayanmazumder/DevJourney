#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Stack
{
    Node *top;
};

void push(Stack &stack, int data)
{
    Node *node = new Node{data, stack.top};
    stack.top = node;
}

int pop(Stack &stack)
{
    if (!stack.top)
    {
        return -1;
    }
    Node *temp = stack.top;
    int value = temp->data;
    stack.top = temp->next;
    delete temp;
    return value;
}

void display(const Stack &stack)
{
    const Node *current = stack.top;
    while (current)
    {
        cout << current->data << ' ';
        current = current->next;
    }
    cout << '\n';
}

void clearStack(Stack &stack)
{
    while (stack.top)
    {
        pop(stack);
    }
}

int main()
{
    Stack stack{nullptr};
    push(stack, 5);
    push(stack, 10);
    push(stack, 15);
    display(stack);
    cout << pop(stack) << '\n';
    display(stack);
    clearStack(stack);
    return 0;
}
