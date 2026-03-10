#include <bits/stdc++.h>
using namespace std;
struct Node
{
    string sym;
    int freq;
    Node *l, *r;
    Node(string s, int f) : sym(s), freq(f), l(nullptr), r(nullptr) {}
};
struct Cmp
{
    bool operator()(Node *a, Node *b) const { return a->freq > b->freq; }
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
    printCodes(root->l, code + '0');
    printCodes(root->r, code + '1');
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n))
        return 0;
    priority_queue<Node *, vector<Node *>, Cmp> pq;
    for (int i = 0; i < n; i++)
    {
        string s;
        int f;
        cin >> s >> f;
        pq.push(new Node(s, f));
    }
    while (pq.size() > 1)
    {
        Node *a = pq.top();
        pq.pop();
        Node *b = pq.top();
        pq.pop();
        Node *p = new Node("", a->freq + b->freq);
        p->l = a;
        p->r = b;
        pq.push(p);
    }
    if (!pq.empty())
        printCodes(pq.top(), "");
    return 0;
}