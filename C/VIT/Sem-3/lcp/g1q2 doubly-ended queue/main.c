#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct Deque
{
    Node *front;
    Node *rear;
} Deque;

Node *newNode(char d)
{
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n)
        return NULL;
    n->data = d;
    n->prev = n->next = NULL;
    return n;
}

void initDeque(Deque *dq)
{
    dq->front = dq->rear = NULL;
}

void enqueue(Deque *dq, char x)
{
    Node *temp = newNode(x);
    if (!temp)
        return;
    if (!dq->front)
    {
        dq->front = dq->rear = temp;
    }
    else
    {
        dq->rear->next = temp;
        temp->prev = dq->rear;
        dq->rear = temp;
    }
}

int dequeue(Deque *dq)
{
    if (!dq->front)
        return 0;
    Node *temp = dq->front;
    dq->front = dq->front->next;
    if (dq->front)
        dq->front->prev = NULL;
    else
        dq->rear = NULL;
    free(temp);
    return 1;
}

void display(Deque *dq)
{
    if (!dq->front)
    {
        printf("-1\n");
        return;
    }
    Node *cur = dq->front;
    while (cur)
    {
        printf("%c", cur->data);
        if (cur->next)
            printf(" ");
        cur = cur->next;
    }
    printf("\n");
}

char getMin(Deque *dq)
{
    if (!dq->front)
        return '-';
    char mn = dq->front->data;
    Node *cur = dq->front;
    while (cur)
    {
        if (cur->data < mn)
            mn = cur->data;
        cur = cur->next;
    }
    return mn;
}

char getMax(Deque *dq)
{
    if (!dq->front)
        return '-';
    char mx = dq->front->data;
    Node *cur = dq->front;
    while (cur)
    {
        if (cur->data > mx)
            mx = cur->data;
        cur = cur->next;
    }
    return mx;
}

int main()
{
    int n;
    if (scanf("%d", &n) != 1)
        return 0;

    Deque dq;
    initDeque(&dq);

    for (int i = 0; i < n; i++)
    {
        char x;
        scanf(" %c", &x);
        enqueue(&dq, x);
    }

    display(&dq);

    int d;
    scanf("%d", &d);

    int ok = 1;
    for (int i = 0; i < d; i++)
    {
        if (!dequeue(&dq))
            ok = 0;
    }

    if (!ok)
    {
        printf("-1\n-1\n-1\n");
        return 0;
    }

    display(&dq);
    printf("%c\n", getMax(&dq));
    printf("%c\n", getMin(&dq));

    return 0;
}
