#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertBeg(int val)
{
    struct Node *nn = malloc(sizeof(struct Node));
    nn->data = val;
    nn->prev = NULL;
    nn->next = head;
    if (head != NULL)
        head->prev = nn;
    head = nn;
}

void insertEnd(int val)
{
    struct Node *nn = malloc(sizeof(struct Node));
    nn->data = val;
    nn->next = NULL;
    nn->prev = NULL;

    if (head == NULL)
    {
        head = nn;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = nn;
    nn->prev = temp;
}

void insertMiddle(int val)
{
    int pos, count = 1;
    printf("Enter the number of nodes after which to insert: ");
    scanf("%d", &pos);

    struct Node *nn = malloc(sizeof(struct Node));
    nn->data = val;
    nn->next = nn->prev = NULL;

    if (head == NULL)
    {
        head = nn;
        return;
    }

    struct Node *temp = head;
    while (count < pos && temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }

    if (count < pos)
    {
        printf("Invalid position!\n");
        free(nn);
        return;
    }

    nn->next = temp->next;
    nn->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = nn;
    temp->next = nn;
}

void deleteBeg()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Deleted item: %d\n", temp->data);
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
}

void deleteEnd()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    printf("Deleted item: %d\n", temp->data);

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);
}

void deleteMiddle()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    int delval;
    printf("Enter the value to delete: ");
    scanf("%d", &delval);

    struct Node *temp = head;
    while (temp != NULL && temp->data != delval)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Value not found.\n");
        return;
    }

    printf("Deleted item: %d\n", temp->data);

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, val;

    do
    {
        printf("\n1.InsertBeg  2.InsertEnd  3.InsertMiddle\n");
        printf("4.DeleteBeg  5.DeleteEnd  6.DeleteMiddle  7.Display  8.Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            insertBeg(val);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &val);
            insertEnd(val);
            break;
        case 3:
            printf("Enter value: ");
            scanf("%d", &val);
            insertMiddle(val);
            break;
        case 4:
            deleteBeg();
            break;
        case 5:
            deleteEnd();
            break;
        case 6:
            deleteMiddle();
            break;
        case 7:
            display();
            break;
        case 8:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 8);

    return 0;
}
