#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void insEnd(int v)
{
    Node *nn = (Node *)malloc(sizeof(Node));
    nn->data = v;
    if (!head)
    {
        head = nn;
        nn->next = head;
        return;
    }
    Node *t = head;
    while (t->next != head)
        t = t->next;
    t->next = nn;
    nn->next = head;
}

void insAfterPos(int pos, int value)
{
    if (!head)
    {
        insEnd(value);
        return;
    }
    Node *t = head;
    int i = 1;
    while (i < pos && t->next != head)
    {
        t = t->next;
        i++;
    }
    Node *nn = (Node *)malloc(sizeof(Node));
    nn->data = value;
    nn->next = t->next;
    t->next = nn;
}

void delNode(int value)
{
    if (!head)
        return;
    if (head->data == value)
    {
        if (head->next == head)
        {
            free(head);
            head = NULL;
            return;
        }
        Node *tail = head;
        while (tail->next != head)
            tail = tail->next;
        tail->next = head->next;
        Node *todel = head;
        head = head->next;
        free(todel);
        return;
    }
    Node *prev = head;
    Node *curr = head->next;
    while (curr != head)
    {
        if (curr->data == value)
        {
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void revList()
{
    if (!head || head->next == head)
        return;
    Node *prev = NULL, *curr = head, *next = NULL;
    Node *start = head;
    do
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != start);
    head->next = prev;
    head = prev;
}

void printList()
{
    if (!head)
    {
        printf("\n");
        return;
    }
    Node *t = head;
    do
    {
        printf("%d ", t->data);
        t = t->next;
    } while (t != head);
    printf("\n");
}

int main()
{
    int n;
    if (scanf("%d", &n) != 1)
        return 0;

    for (int i = 0; i < n; ++i)
    {
        int v;
        scanf("%d", &v);
        insEnd(v);
    }

    int pos, val;
    scanf("%d %d", &pos, &val);
    insAfterPos(pos, val);

    int *rest = NULL, restCap = 0, restSize = 0;
    int x;
    while (scanf("%d", &x) == 1)
    {
        if (restSize == restCap)
        {
            restCap = restCap ? restCap * 2 : 8;
            rest = realloc(rest, restCap * sizeof(int));
        }
        rest[restSize++] = x;
    }

    if (restSize == 0)
    {

        printList();
        printList();
        revList();
        printList();
        free(rest);
        return 0;
    }

    int delVal = rest[restSize - 1];

    int m, startIdx;
    if (restSize >= 2 && rest[0] == restSize - 2)
    {
        m = rest[0];
        startIdx = 1;
    }
    else
    {
        m = restSize - 1;
        startIdx = 0;
    }

    for (int i = 0; i < m; ++i)
    {
        insEnd(rest[startIdx + i]);
    }

    printList();

    delNode(delVal);

    printList();

    revList();
    printList();

    free(rest);
    return 0;
}