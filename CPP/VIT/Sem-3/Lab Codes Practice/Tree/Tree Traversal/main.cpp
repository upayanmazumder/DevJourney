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

void preorder(const Node *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << ' ';
    preorder(root->left);
    preorder(root->right);
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

void postorder(const Node *root)
{
    if (!root)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << ' ';
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
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    preorder(root);
    cout << '\n';
    inorder(root);
    cout << '\n';
    postorder(root);
    cout << '\n';

    clearTree(root);
    return 0;
}
