#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node
{
    string sym;
    int freq;
    Node *l, *r;

    Node(string s, int f)
    {
        sym = s;
        freq = f;
        l = nullptr;
        r = nullptr;
    }
};

void printCodes(Node *root, string code)
{
    if (!root)
        return;

    if (!root->l && !root->r)
    {
        cout << root->sym << ": " << code << "\n";
        return;
    }

    printCodes(root->l, code + "0");
    printCodes(root->r, code + "1");
}

int findMin(vector<Node *> &nodes)
{
    int idx = 0;
    for (int i = 1; i < nodes.size(); i++)
    {
        if (nodes[i]->freq < nodes[idx]->freq)
            idx = i;
    }
    return idx;
}

int main()
{
    int n;
    cin >> n;

    vector<Node *> nodes;

    for (int i = 0; i < n; i++)
    {
        string s;
        int f;
        cin >> s >> f;
        nodes.push_back(new Node(s, f));
    }

    while (nodes.size() > 1)
    {
        int i1 = findMin(nodes);
        Node *a = nodes[i1];
        nodes.erase(nodes.begin() + i1);

        int i2 = findMin(nodes);
        Node *b = nodes[i2];
        nodes.erase(nodes.begin() + i2);

        Node *p = new Node("", a->freq + b->freq);
        p->l = a;
        p->r = b;

        nodes.push_back(p);
    }

    if (!nodes.empty())
        printCodes(nodes[0], "");

    return 0;
}