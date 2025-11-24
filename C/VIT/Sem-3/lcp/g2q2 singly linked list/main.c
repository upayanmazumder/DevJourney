#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *newNode(int d)
{
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n)
        return NULL;
    n->data = d;
    n->next = NULL;
    return n;
}

// Insert at end
void insertEnd(Node **head, int value)
{
    Node *temp = newNode(value);
    if (!temp)
        return;
    if (*head == NULL)
    {
        *head = temp;
        return;
    }
    Node *curr = *head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
}

// Insert at beginning
void insertBeginning(Node **head, int value)
{
    Node *temp = newNode(value);
    if (!temp)
        return;
    temp->next = *head;
    *head = temp;
}

// Insert at given position (1-based)
void insertPosition(Node **head, int pos, int value)
{
    if (pos == 1)
    {
        insertBeginning(head, value);
        return;
    }

    Node *curr = *head;
    for (int i = 1; i < pos - 1 && curr != NULL; i++)
        curr = curr->next;

    if (curr == NULL)
        return; // invalid pos

    Node *temp = newNode(value);
    if (!temp)
        return;
    temp->next = curr->next;
    curr->next = temp;
}

// Delete element at given position (1-based)
void deletePosition(Node **head, int pos)
{
    if (*head == NULL)
        return;

    if (pos == 1)
    {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node *curr = *head;
    for (int i = 1; i < pos - 1 && curr->next != NULL; i++)
        curr = curr->next;

    if (curr->next == NULL)
        return;

    Node *temp = curr->next;
    curr->next = temp->next;
    free(temp);
}

void display(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        printf("%d", curr->data);
        if (curr->next != NULL)
            printf(",");
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    int n;
    if (scanf("%d", &n) != 1)
        return 0;

    Node *head = NULL;

    // create list
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        insertEnd(&head, x);
    }

    display(head);

    // delete at position
    int delPos;
    scanf("%d", &delPos);
    deletePosition(&head, delPos);
    display(head);

    // insert at end
    int endVal;
    scanf("%d", &endVal);
    insertEnd(&head, endVal);
    display(head);

    // insert at beginning
    int begVal;
    scanf("%d", &begVal);
    insertBeginning(&head, begVal);
    display(head);

    // insert at a given position
    int pos, val;
    scanf("%d %d", &pos, &val);
    insertPosition(&head, pos, val);
    display(head);

    return 0;
}
