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

Node *search(Node *root, int data)
{
    if (!root || root->data == data)
    {
        return root;
    }
    if (data < root->data)
    {
        return search(root->left, data);
    }
    return search(root->right, data);
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
    Node *found = search(root, 60);
    if (found)
    {
        cout << "Found\n";
    }
    else
    {
        cout << "Not found\n";
    }
    found = search(root, 25);
    if (found)
    {
        cout << "Found\n";
    }
    else
    {
        cout << "Not found\n";
    }
    clearTree(root);
    return 0;
}
