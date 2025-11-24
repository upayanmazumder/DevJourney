#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *newNode(int d)
{
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n)
        return NULL;
    n->data = d;
    n->left = n->right = NULL;
    return n;
}

Node *insertNode(Node *root, int value)
{
    if (root == NULL)
        return newNode(value);

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else
        root->right = insertNode(root->right, value);

    return root;
}

Node *findMin(Node *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        // Two children: replace with inorder successor
        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Node *root)
{
    if (!root)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    int n;
    if (scanf("%d", &n) != 1)
        return 0;

    Node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        root = insertNode(root, x);
    }

    // Display initial traversals
    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);
    printf("\n");

    int del;
    scanf("%d", &del);

    root = deleteNode(root, del);

    // After deletion (only inorder required)
    inorder(root);
    printf("\n");

    return 0;
}
