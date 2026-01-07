#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int freq;
    Node *left, *right;

    Node(int f) {
        freq = f;
        left = right = NULL;
    }
};

class Compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string code) {
    if (!root)
        return;

    if (!root->left && !root->right) {
        cout << code << " ";
        return;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    int n;
    cin >> n;

    int freq[100];
    for (int i = 0; i < n; i++)
        cin >> freq[i];

    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < n; i++)
        pq.push(new Node(freq[i]));

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* parent = new Node(left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    printCodes(pq.top(), "");
    return 0;
}
