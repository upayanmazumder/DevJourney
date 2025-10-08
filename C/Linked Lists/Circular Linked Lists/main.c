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

void insertPos(int val, int pos)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = val;

    if (pos == 1)
    {
        insertBeg(val);
        return;
    }

    struct Node *temp = head;
    int count = 1;

    while (count < pos - 1 && temp->next != head)
    {
        temp = temp->next;
        count++;
    }

    if (count < pos - 1)
    {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
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

void deletePos(int pos)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    if (pos == 1)
    {
        deleteBeg();
        return;
    }

    struct Node *prev = NULL;
    int count = 1;

    while (count < pos && temp->next != head)
    {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (count < pos)
    {
        printf("Position out of range\n");
        return;
    }

    prev->next = temp->next;
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
    int choice, val, pos;

    do
    {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
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
            printf("Enter value and position: ");
            scanf("%d%d", &val, &pos);
            insertPos(val, pos);
            break;
        case 4:
            deleteBeg();
            break;
        case 5:
            deleteEnd();
            break;
        case 6:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            deletePos(pos);
            break;
        case 7:
            display();
            break;
        case 8:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 8);

    return 0;
}
