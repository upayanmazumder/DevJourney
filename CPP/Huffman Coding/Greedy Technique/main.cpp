#include <iostream>
using namespace std;

class Node {
public:
    int freq;
    Node *left, *right;
};

Node* heap[100];
int heapSize = 0;

Node* newNode(int f) {
    Node* temp = new Node();
    temp->freq = f;
    temp->left = temp->right = NULL;
    return temp;
}

void swap(Node* &a, Node* &b) {
    Node* t = a;
    a = b;
    b = t;
}

void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2]->freq > heap[i]->freq) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < heapSize && heap[l]->freq < heap[smallest]->freq)
        smallest = l;

    if (r < heapSize && heap[r]->freq < heap[smallest]->freq)
        smallest = r;

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapifyDown(smallest);
    }
}

void insert(Node* node) {
    heap[heapSize] = node;
    heapifyUp(heapSize);
    heapSize++;
}

Node* extractMin() {
    Node* root = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;
    heapifyDown(0);
    return root;
}

void printCodes(Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (!root->left && !root->right) {
        for (int i = 0; i < top; i++)
            cout << arr[i];
        cout << " ";
    }
}

int main() {
    int n;
    cin >> n;

    int freq[100];
    for (int i = 0; i < n; i++)
        cin >> freq[i];

    for (int i = 0; i < n; i++)
        insert(newNode(freq[i]));

    while (heapSize > 1) {
        Node* left = extractMin();
        Node* right = extractMin();

        Node* parent = newNode(left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        insert(parent);
    }

    int arr[100];
    printCodes(heap[0], arr, 0);

    return 0;
}
