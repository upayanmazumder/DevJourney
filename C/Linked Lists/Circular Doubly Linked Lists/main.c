#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

void insertBeg(int val)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = val;

    if (!head)
    {
        newNode->next = newNode->prev = newNode;
        head = newNode;
        return;
    }

    struct Node *last = head->prev;

    newNode->next = head;
    newNode->prev = last;
    last->next = head->prev = newNode;
    head = newNode;
}

void insertEnd(int val)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = val;

    if (!head)
    {
        newNode->next = newNode->prev = newNode;
        head = newNode;
        return;
    }

    struct Node *last = head->prev;

    newNode->next = head;
    newNode->prev = last;
    last->next = head->prev = newNode;
}

void insertPos(int val, int pos)
{
    if (pos == 1)
    {
        insertBeg(val);
        return;
    }

    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = val;

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

    struct Node *nextNode = temp->next;
    newNode->next = nextNode;
    newNode->prev = temp;
    temp->next = nextNode->prev = newNode;
}

void deleteBeg()
{
    if (!head)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    if (head->next == head)
    {
        head = NULL;
    }
    else
    {
        struct Node *last = head->prev;
        head = head->next;
        head->prev = last;
        last->next = head;
    }

    printf("Deleted item: %d\n", temp->data);
    free(temp);
}

void deleteEnd()
{
    if (!head)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *last = head->prev;
    if (last == head)
    {
        head = NULL;
    }
    else
    {
        struct Node *prev = last->prev;
        prev->next = head;
        head->prev = prev;
    }

    printf("Deleted item: %d\n", last->data);
    free(last);
}

void deletePos(int pos)
{
    if (!head)
    {
        printf("List is empty\n");
        return;
    }

    if (pos == 1)
    {
        deleteBeg();
        return;
    }

    struct Node *temp = head;
    int count = 1;
    while (count < pos && temp->next != head)
    {
        temp = temp->next;
        count++;
    }

    if (count < pos)
    {
        printf("Position out of range\n");
        return;
    }

    struct Node *prev = temp->prev;
    struct Node *next = temp->next;
    prev->next = next;
    next->prev = prev;

    printf("Deleted item: %d\n", temp->data);
    free(temp);
}

void displayForward()
{
    if (!head)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    printf("Forward: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void displayBackward()
{
    if (!head)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head->prev;
    struct Node *start = temp;
    printf("Backward: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    } while (temp != start);
    printf("\n");
}

int main()
{
    int choice, val, pos;

    do
    {
        printf("\n--- Circular Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n");
        printf("4. Delete from Beginning\n5. Delete from End\n6. Delete from Position\n");
        printf("7. Display Forward\n8. Display Backward\n9. Exit\n");
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
            scanf("%d %d", &val, &pos);
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
            displayForward();
            break;
        case 8:
            displayBackward();
            break;
        case 9:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 9);

    return 0;
}
