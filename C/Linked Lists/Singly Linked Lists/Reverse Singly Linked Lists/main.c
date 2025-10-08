#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

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

void reverse()
{
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    printf("List reversed!\n");
}

int main()
{
    int ch, val;
    do
    {
        printf("\n1.Insert 2.Display 3.Reverse 4.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Val: ");
            scanf("%d", &val);
            insertEnd(val);
            break;
        case 2:
            display();
            break;
        case 3:
            reverse();
            break;
        }
    } while (ch != 4);
}
