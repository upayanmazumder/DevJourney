#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *create_node(int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = node;
    return node;
}

void insert_end(Node **head, int data) {
    Node *node = create_node(data);
    if (!*head) {
        *head = node;
        return;
    }
    Node *tail = *head;
    while (tail->next != *head) {
        tail = tail->next;
    }
    tail->next = node;
    node->next = *head;
}

void delete_value(Node **head, int data) {
    if (!*head) {
        return;
    }
    Node *current = *head;
    Node *previous = NULL;
    do {
        if (current->data == data) {
            if (previous) {
                previous->next = current->next;
            } else {
                Node *tail = *head;
                while (tail->next != *head) {
                    tail = tail->next;
                }
                if (current->next == current) {
                    *head = NULL;
                    free(current);
                    return;
                }
                *head = current->next;
                tail->next = *head;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    } while (current != *head);
}

void display(Node *head) {
    if (!head) {
        printf("\n");
        return;
    }
    Node *current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main(void) {
    Node *head = NULL;
    insert_end(&head, 2);
    insert_end(&head, 4);
    insert_end(&head, 6);
    display(head);
    delete_value(&head, 4);
    display(head);
    while (head) {
        Node *tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        if (head->next == head) {
            free(head);
            break;
        }
        Node *temp = head;
        head = head->next;
        tail->next = head;
        free(temp);
    }
    return 0;
}
