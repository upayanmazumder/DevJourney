#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertBeg(int val)
{
    struct Node *n = malloc(sizeof(struct Node));
    n->data = val;
    n->next = head;
    head = n;
}

void insertEnd(int val)
{
    struct Node *n = malloc(sizeof(struct Node));
    n->data = val;
    n->next = NULL;
    if (!head)
    {
        head = n;
        return;
    }

    struct Node *t = head;
    while (t->next)
        t = t->next;
    t->next = n;
}

void deleteBeg()
{
    if (!head)
    {
        printf("Empty list\n");
        return;
    }
    struct Node *t = head;
    head = head->next;
    printf("Deleted %d\n", t->data);
    free(t);
}

void deleteEnd()
{
    if (!head)
    {
        printf("Empty list\n");
        return;
    }
    struct Node *t = head, *p = NULL;
    while (t->next)
    {
        p = t;
        t = t->next;
    }
    if (p)
        p->next = NULL;
    else
        head = NULL;
    printf("Deleted %d\n", t->data);
    free(t);
}

void display()
{
    struct Node *t = head;
    if (!t)
    {
        printf("Empty\n");
        return;
    }
    while (t)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main()
{
    int ch, val;
    do
    {
        printf("\n1.InsertBeg 2.InsertEnd 3.DelBeg 4.DelEnd 5.Display 6.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Val: ");
            scanf("%d", &val);
            insertBeg(val);
            break;
        case 2:
            printf("Val: ");
            scanf("%d", &val);
            insertEnd(val);
            break;
        case 3:
            deleteBeg();
            break;
        case 4:
            deleteEnd();
            break;
        case 5:
            display();
            break;
        }
    } while (ch != 6);
}
