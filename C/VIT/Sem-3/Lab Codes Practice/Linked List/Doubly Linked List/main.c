#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *create_node(int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void insert_end(Node **head, int data) {
    Node *node = create_node(data);
    if (!*head) {
        *head = node;
        return;
    }
    Node *current = *head;
    while (current->next) {
        current = current->next;
    }
    current->next = node;
    node->prev = current;
}

void delete_value(Node **head, int data) {
    Node *current = *head;
    while (current) {
        if (current->data == data) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                *head = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
}

void display_forward(Node *head) {
    Node *current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void display_backward(Node *head) {
    Node *current = head;
    if (!current) {
        printf("\n");
        return;
    }
    while (current->next) {
        current = current->next;
    }
    while (current) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

int main(void) {
    Node *head = NULL;
    insert_end(&head, 5);
    insert_end(&head, 10);
    insert_end(&head, 15);
    display_forward(head);
    display_backward(head);
    delete_value(&head, 10);
    display_forward(head);
    display_backward(head);
    while (head) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
