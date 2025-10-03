// 1.Write and Implement Binary Search Tree methods, such as Insertion,Deletion,
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left, *right;
};
struct Node *crN(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node *ins(struct Node *root, int data)
{
    if (root == NULL)
        return crN(data);
    if (data < root->data)
        root->left = ins(root->left, data);
    else if (data > root->data)
        root->right = ins(root->right, data);
    return root;
}
struct Node *fMin(struct Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}
struct Node *delN(struct Node *root, int data)
{
    if (root == NULL)
        return root;
    if (data < root->data)
        root->left = delN(root->left, data);
    else if (data > root->data)
        root->right = delN(root->right, data);
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node *temp = fMin(root->right);
        root->data = temp->data;
        root->right = delN(root->right, temp->data);
    }
    return root;
}
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int elements[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &elements[i]);
    }
    int delE;
    scanf("%d", &delE);
    struct Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = ins(root, elements[i]);
    }
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    root = delN(root, delE);
    inorder(root);
    return 0;
}