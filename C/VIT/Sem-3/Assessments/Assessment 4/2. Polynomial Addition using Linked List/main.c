// 2. Write and implement a polynomial addition by linked list using C language.

#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int coeff;
    int power;
    struct Node *next;
} Node;

Node *cN(int coeff, int power)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

void iN(Node **poly, int coeff, int power)
{
    Node *newNode = cN(coeff, power);
    if (*poly == NULL)
    {
        *poly = newNode;
    }
    else
    {
        Node *temp = *poly;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

Node *rP()
{
    int terms;
    scanf("%d", &terms);
    Node *poly = NULL;
    for (int i = 0; i < terms; i++)
    {
        int c, p;
        scanf("%d %d", &c, &p);
        iN(&poly, c, p);
    }
    return poly;
}

Node *addP(Node *poly1, Node *poly2)
{
    Node *result = NULL;
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->power == poly2->power)
        {
            iN(&result, poly1->coeff + poly2->coeff, poly1->power);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->power > poly2->power)
        {
            iN(&result, poly1->coeff, poly1->power);
            poly1 = poly1->next;
        }
        else
        {
            iN(&result, poly2->coeff, poly2->power);
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL)
    {
        iN(&result, poly1->coeff, poly1->power);
        poly1 = poly1->next;
    }

    while (poly2 != NULL)
    {
        iN(&result, poly2->coeff, poly2->power);
        poly2 = poly2->next;
    }

    return result;
}

void display(Node *poly)
{
    while (poly != NULL)
    {
        printf("(%d,%d)", poly->coeff, poly->power);
        if (poly->next != NULL)
            printf(" -> ");
        poly = poly->next;
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    Node *result = NULL;
    for (int i = 0; i < n; i++)
    {
        int pI;
        scanf("%d", &pI);
        Node *current = rP();
        if (result == NULL)
        {
            result = current;
        }
        else
        {
            result = addP(result, current);
        }
    }

    display(result);
    return 0;
}