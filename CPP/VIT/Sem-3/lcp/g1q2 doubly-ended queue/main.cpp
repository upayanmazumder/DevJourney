#include <iostream>
#include <string>
using namespace std;

struct Node
{
    char data;
    Node *prev;
    Node *next;
    Node(char d) : data(d), prev(NULL), next(NULL) {}
};

class Deque
{
    Node *front;
    Node *rear;

public:
    Deque() : front(NULL), rear(NULL) {}

    void enqueue(char x)
    {
        Node *temp = new Node(x);
        if (!front)
        {
            front = rear = temp;
        }
        else
        {
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
        }
    }

    bool dequeue()
    {
        if (!front)
            return false;

        Node *temp = front;
        front = front->next;

        if (front)
            front->prev = NULL;
        else
            rear = NULL;

        delete temp;
        return true;
    }

    void display()
    {
        if (!front)
        {
            cout << "-1\n";
            return;
        }
        Node *cur = front;
        while (cur)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << "\n";
    }

    char getMin()
    {
        if (!front)
            return '-';
        char mn = front->data;
        Node *cur = front;
        while (cur)
        {
            if (cur->data < mn)
                mn = cur->data;
            cur = cur->next;
        }
        return mn;
    }

    char getMax()
    {
        if (!front)
            return '-';
        char mx = front->data;
        Node *cur = front;
        while (cur)
        {
            if (cur->data > mx)
                mx = cur->data;
            cur = cur->next;
        }
        return mx;
    }
};

int main()
{
    int n;
    cin >> n;

    Deque dq;

    for (int i = 0; i < n; i++)
    {
        char x;
        cin >> x;
        dq.enqueue(x);
    }

    dq.display();

    int d;
    cin >> d;

    bool ok = true;
    for (int i = 0; i < d; i++)
    {
        if (!dq.dequeue())
            ok = false;
    }

    if (!ok)
    {
        cout << "-1\n-1\n-1\n";
        return 0;
    }

    dq.display();

    cout << dq.getMax() << "\n";
    cout << dq.getMin() << "\n";

    return 0;
}
