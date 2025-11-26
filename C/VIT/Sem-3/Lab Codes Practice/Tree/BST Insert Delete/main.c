#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *create_node(int data)
{
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *insert(Node *root, int data)
{
    if (!root)
    {
        return create_node(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

Node *min_value_node(Node *node)
{
    Node *current = node;
    while (current && current->left)
    {
        current = current->left;
    }
    return current;
}

Node *delete_node(Node *root, int data)
{
    if (!root)
    {
        return NULL;
    }
    if (data < root->data)
    {
        root->left = delete_node(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete_node(root->right, data);
    }
    else
    {
        if (!root->left)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        if (!root->right)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = min_value_node(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

void inorder(Node *root)
{
    if (!root)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(void)
{
    Node *root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++)
    {
        root = insert(root, values[i]);
    }
    inorder(root);
    printf("\n");
    root = delete_node(root, 20);
    root = delete_node(root, 30);
    root = delete_node(root, 50);
    inorder(root);
    printf("\n");
    return 0;
}
