#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data)
{
    return new Node{data, nullptr, nullptr};
}

Node *insert(Node *root, int data)
{
    if (!root)
    {
        return createNode(data);
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

Node *minValueNode(Node *node)
{
    Node *current = node;
    while (current && current->left)
    {
        current = current->left;
    }
    return current;
}

Node *deleteNode(Node *root, int data)
{
    if (!root)
    {
        return nullptr;
    }
    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if (!root->left)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(const Node *root)
{
    if (!root)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << ' ';
    inorder(root->right);
}

void clearTree(Node *&root)
{
    if (!root)
    {
        return;
    }
    clearTree(root->left);
    clearTree(root->right);
    delete root;
    root = nullptr;
}

int main()
{
    Node *root = nullptr;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int value : values)
    {
        root = insert(root, value);
    }
    inorder(root);
    cout << '\n';
    root = deleteNode(root, 20);
    root = deleteNode(root, 30);
    root = deleteNode(root, 50);
    inorder(root);
    cout << '\n';
    clearTree(root);
    return 0;
}
