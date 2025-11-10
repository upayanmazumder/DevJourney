#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *createNode(int data)
{
    Node *node = new Node{data, nullptr};
    return node;
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
}

void deleteValue(Node *&head, int data)
{
    Node *current = head;
    Node *previous = nullptr;
    while (current)
    {
        if (current->data == data)
        {
            if (previous)
            {
                previous->next = current->next;
            }
            else
            {
                head = current->next;
            }
            delete current;
            return;
        }
        previous = current;
        current = current->next;
    }
}

void display(const Node *head)
{
    const Node *current = head;
    while (current)
    {
        cout << current->data << ' ';
        current = current->next;
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
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    display(head);
    deleteValue(head, 20);
    display(head);
    clearList(head);
    return 0;
}
