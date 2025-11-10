#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Queue
{
    Node *front;
    Node *rear;
};

void enqueue(Queue &queue, int data)
{
    Node *node = new Node{data, nullptr};
    if (!queue.rear)
    {
        queue.front = node;
        queue.rear = node;
        return;
    }
    queue.rear->next = node;
    queue.rear = node;
}

int dequeue(Queue &queue)
{
    if (!queue.front)
    {
        return -1;
    }
    Node *temp = queue.front;
    int value = temp->data;
    queue.front = temp->next;
    if (!queue.front)
    {
        queue.rear = nullptr;
    }
    delete temp;
    return value;
}

void display(const Queue &queue)
{
    const Node *current = queue.front;
    while (current)
    {
        cout << current->data << ' ';
        current = current->next;
    }
    cout << '\n';
}

void clearQueue(Queue &queue)
{
    while (queue.front)
    {
        dequeue(queue);
    }
}

int main()
{
    Queue queue{nullptr, nullptr};
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);
    cout << dequeue(queue) << '\n';
    display(queue);
    clearQueue(queue);
    return 0;
}
