#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    double W;
    if (!(cin >> n >> W))
        return 0;
    vector<pair<double, double>> items(n);
    for (int i = 0; i < n; i++)
        cin >> items[i].first >> items[i].second; // weight, value
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b)
         { return items[a].second / items[a].first > items[b].second / items[b].first; });
    double total = 0;
    for (int i = 0; i < n && W > 1e-12; ++i)
    {
        int id = idx[i];
        if (items[id].first <= W)
        {
            total += items[id].second;
            W -= items[id].first;
        }
        else
        {
            total += items[id].second * (W / items[id].first);
            W = 0;
        }
    }
    cout << fixed << setprecision(4) << total << "\n";
    return 0;
}
