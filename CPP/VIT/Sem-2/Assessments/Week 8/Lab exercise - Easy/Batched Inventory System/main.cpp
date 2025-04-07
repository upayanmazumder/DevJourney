#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, val;
    cin >> n;

    vector<int> items;

    for (int i = 0; i < n; ++i) {
        cin >> val;
        items.push_back(val);
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> val;
        items.push_back(val);
    }

    sort(items.begin(), items.end());

    for (int id : items) {
        cout << id << " ";
    }

    cout << endl;
    return 0;
}