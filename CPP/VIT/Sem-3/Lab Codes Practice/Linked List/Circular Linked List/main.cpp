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
    node->next = node;
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
    Node *tail = head;
    while (tail->next != head)
    {
        tail = tail->next;
    }
    tail->next = node;
    node->next = head;
}

void deleteValue(Node *&head, int data)
{
    if (!head)
    {
        return;
    }
    Node *current = head;
    Node *previous = nullptr;
    do
    {
        if (current->data == data)
        {
            if (previous)
            {
                previous->next = current->next;
            }
            else
            {
                Node *tail = head;
                while (tail->next != head)
                {
                    tail = tail->next;
                }
                if (current->next == current)
                {
                    delete current;
                    head = nullptr;
                    return;
                }
                head = current->next;
                tail->next = head;
            }
            delete current;
            return;
        }
        previous = current;
        current = current->next;
    } while (current != head);
}

void display(const Node *head)
{
    if (!head)
    {
        cout << '\n';
        return;
    }
    const Node *current = head;
    do
    {
        cout << current->data << ' ';
        current = current->next;
    } while (current != head);
    cout << '\n';
}

void clearList(Node *&head)
{
    if (!head)
    {
        return;
    }
    Node *current = head->next;
    while (current != head)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    delete head;
    head = nullptr;
}

int main()
{
    Node *head = nullptr;
    insertEnd(head, 2);
    insertEnd(head, 4);
    insertEnd(head, 6);
    display(head);
    deleteValue(head, 4);
    display(head);
    clearList(head);
    return 0;
}
