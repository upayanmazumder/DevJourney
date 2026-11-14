#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *create_node(int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *insert(Node *root, int data) {
    if (!root) {
        return create_node(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

Node *search(Node *root, int data) {
    if (!root || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

int main(void) {
    Node *root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) {
        root = insert(root, values[i]);
    }
    Node *found = search(root, 60);
    if (found) {
        printf("Found\n");
    } else {
        printf("Not found\n");
    }
    found = search(root, 25);
    if (found) {
        printf("Found\n");
    } else {
        printf("Not found\n");
    }
    return 0;
}
