#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *create_node(int data)
{
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void insert_end(Node **head, int data)
{
    Node *node = create_node(data);
    if (!*head)
    {
        *head = node;
        return;
    }
    Node *current = *head;
    while (current->next)
    {
        current = current->next;
    }
    current->next = node;
}

void delete_value(Node **head, int data)
{
    Node *current = *head;
    Node *previous = NULL;
    while (current)
    {
        if (current->data == data)
        {
            if (previous)
            {
                previous->next = current->next;
            }
            else
            {
                *head = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void display(Node *head)
{
    Node *current = head;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(void)
{
    Node *head = NULL;
    insert_end(&head, 10);
    insert_end(&head, 20);
    insert_end(&head, 30);
    display(head);
    delete_value(&head, 20);
    display(head);
    while (head)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
