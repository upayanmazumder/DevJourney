#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

// Insert at end
void insertEnd(Node *&head, int value)
{
    Node *temp = new Node(value);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    Node *curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
}

// Insert at beginning
void insertBeginning(Node *&head, int value)
{
    Node *temp = new Node(value);
    temp->next = head;
    head = temp;
}

// Insert at given position (1-based)
void insertPosition(Node *&head, int pos, int value)
{
    if (pos == 1)
    {
        insertBeginning(head, value);
        return;
    }

    Node *curr = head;
    for (int i = 1; i < pos - 1 && curr != NULL; i++)
        curr = curr->next;

    if (curr == NULL)
        return; // invalid pos

    Node *temp = new Node(value);
    temp->next = curr->next;
    curr->next = temp;
}

// Delete element at given position (1-based)
void deletePosition(Node *&head, int pos)
{
    if (head == NULL)
        return;

    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *curr = head;
    for (int i = 1; i < pos - 1 && curr->next != NULL; i++)
        curr = curr->next;

    if (curr->next == NULL)
        return;

    Node *temp = curr->next;
    curr->next = temp->next;
    delete temp;
}

void display(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data;
        if (curr->next != NULL)
            cout << ",";
        curr = curr->next;
    }
    cout << "\n";
}

int main()
{
    int n;
    cin >> n;

    Node *head = NULL;

    // create list
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insertEnd(head, x);
    }

    display(head);

    // delete at position
    int delPos;
    cin >> delPos;
    deletePosition(head, delPos);
    display(head);

    // insert at end
    int endVal;
    cin >> endVal;
    insertEnd(head, endVal);
    display(head);

    // insert at beginning
    int begVal;
    cin >> begVal;
    insertBeginning(head, begVal);
    display(head);

    // insert at a given position
    int pos, val;
    cin >> pos >> val;
    insertPosition(head, pos, val);
    display(head);

    return 0;
}
