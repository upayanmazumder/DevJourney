#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int d;
    struct Node *p;
    struct Node *n;
};

struct Node *h = NULL;

struct Node *newNode(int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->d = x;
    t->p = t->n = NULL;
    return t;
}

void insEnd(int x)
{
    struct Node *t = newNode(x);
    if (!h)
    {
        h = t;
        return;
    }
    struct Node *c = h;
    while (c->n)
        c = c->n;
    c->n = t;
    t->p = c;
}

void insBeg(int x)
{
    struct Node *t = newNode(x);
    if (!h)
    {
        h = t;
        return;
    }
    t->n = h;
    h->p = t;
    h = t;
}

void insPos(int pos, int x)
{
    if (pos == 1)
    {
        insBeg(x);
        return;
    }
    struct Node *c = h;
    for (int i = 1; i < pos && c; i++)
        c = c->n;
    if (!c)
        return;
    struct Node *t = newNode(x);
    t->n = c->n;
    if (c->n)
        c->n->p = t;
    c->n = t;
    t->p = c;
}

void delVal(int x)
{
    struct Node *c = h;
    while (c && c->d != x)
        c = c->n;
    if (!c)
        return;
    if (c->p)
        c->p->n = c->n;
    else
        h = c->n;
    if (c->n)
        c->n->p = c->p;
    free(c);
}

void rev()
{
    struct Node *c = h, *t = NULL;
    while (c)
    {
        t = c->p;
        c->p = c->n;
        c->n = t;
        c = c->p;
    }
    if (t)
        h = t->p;
}

void print()
{
    struct Node *c = h;
    while (c)
    {
        printf("%d", c->d);
        if (c->n)
            printf(" ");
        c = c->n;
    }
    printf("\n");
}

int main()
{
    int n, x, pos;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        insEnd(x);
    }
    scanf("%d", &pos);
    scanf("%d", &x);
    insPos(pos, x);
    scanf("%d", &x);
    insBeg(x);
    scanf("%d", &x);
    insEnd(x);
    print();
    scanf("%d", &x);
    delVal(x);
    print();
    rev();
    print();
    return 0;
}