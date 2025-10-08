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
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = val;

    if (head == NULL)
    {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != head)
        temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

void insertEnd(int val)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = val;

    if (head == NULL)
    {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

void deleteBeg()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    struct Node *last = head;

    while (last->next != head)
        last = last->next;

    if (head->next == head)
    {
        head = NULL;
    }
    else
    {
        head = head->next;
        last->next = head;
    }

    printf("Deleted item: %d\n", temp->data);
    free(temp);
}

void deleteEnd()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;

    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head)
    {
        head = NULL;
    }
    else
    {
        prev->next = head;
    }

    printf("Deleted item: %d\n", temp->data);
    free(temp);
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main()
{
    int choice, val;
    do
    {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
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
            deleteBeg();
            break;
        case 4:
            deleteEnd();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}
