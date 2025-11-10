#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

Node *createNode(int data)
{
    return new Node{data, nullptr, nullptr};
}

void insertEnd(Node *&head, int data)
{
    Node *node = createNode(data);
    if (!head)
    {
        head = node;
        return;
    }
    Node *current = head;
    while (current->next)
    {
        current = current->next;
    }
    current->next = node;
    node->prev = current;
}

void deleteValue(Node *&head, int data)
{
    Node *current = head;
    while (current)
    {
        if (current->data == data)
        {
            if (current->prev)
            {
                current->prev->next = current->next;
            }
            else
            {
                head = current->next;
            }
            if (current->next)
            {
                current->next->prev = current->prev;
            }
            delete current;
            return;
        }
        current = current->next;
    }
}

void displayForward(const Node *head)
{
    const Node *current = head;
    while (current)
    {
        cout << current->data << ' ';
        current = current->next;
    }
    cout << '\n';
}

void displayBackward(const Node *head)
{
    const Node *current = head;
    if (!current)
    {
        cout << '\n';
        return;
    }
    while (current->next)
    {
        current = current->next;
    }
    while (current)
    {
        cout << current->data << ' ';
        current = current->prev;
    }
    cout << '\n';
}

void clearList(Node *&head)
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    Node *head = nullptr;
    insertEnd(head, 5);
    insertEnd(head, 10);
    insertEnd(head, 15);
    displayForward(head);
    displayBackward(head);
    deleteValue(head, 10);
    displayForward(head);
    displayBackward(head);
    clearList(head);
    return 0;
}
