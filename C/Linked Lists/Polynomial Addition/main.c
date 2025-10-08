#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff, pow;
    struct Node *next;
};

struct Node *createNode(int c, int p)
{
    struct Node *n = malloc(sizeof(struct Node));
    n->coeff = c;
    n->pow = p;
    n->next = NULL;
    return n;
}

void insertEnd(struct Node **head, int c, int p)
{
    struct Node *n = createNode(c, p);
    if (*head == NULL)
    {
        *head = n;
        return;
    }
    struct Node *t = *head;
    while (t->next)
        t = t->next;
    t->next = n;
}

struct Node *addPoly(struct Node *p1, struct Node *p2)
{
    struct Node *res = NULL;
    while (p1 && p2)
    {
        if (p1->pow > p2->pow)
        {
            insertEnd(&res, p1->coeff, p1->pow);
            p1 = p1->next;
        }
        else if (p2->pow > p1->pow)
        {
            insertEnd(&res, p2->coeff, p2->pow);
            p2 = p2->next;
        }
        else
        { // same power
            insertEnd(&res, p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1)
    {
        insertEnd(&res, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2)
    {
        insertEnd(&res, p2->coeff, p2->pow);
        p2 = p2->next;
    }
    return res;
}

void display(struct Node *head)
{
    while (head)
    {
        printf("%dx^%d", head->coeff, head->pow);
        if (head->next)
            printf(" + ");
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct Node *p1 = NULL, *p2 = NULL, *res = NULL;

    // P1: 5x^3 + 4x^2 + 2
    insertEnd(&p1, 5, 3);
    insertEnd(&p1, 4, 2);
    insertEnd(&p1, 2, 0);

    // P2: 3x^3 + 1x + 7
    insertEnd(&p2, 3, 3);
    insertEnd(&p2, 1, 1);
    insertEnd(&p2, 7, 0);

    printf("P1: ");
    display(p1);
    printf("P2: ");
    display(p2);

    res = addPoly(p1, p2);
    printf("Sum: ");
    display(res);
}
