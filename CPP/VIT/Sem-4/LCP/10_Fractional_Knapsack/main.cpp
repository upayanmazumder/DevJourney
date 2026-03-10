#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    double W;
    if (!(cin >> n >> W))
        return 0;
    vector<pair<double, double>> items(n);
    for (int i = 0; i < n; i++)
        cin >> items[i].first >> items[i].second; // weight, value
    vector<int> idx(n);
    for (int i = 0; i < n; ++i)
        idx[i] = i;
    // simple selection sort by value/weight ratio
    for (int i = 0; i < n; ++i)
    {
        int best = i;
        for (int j = i + 1; j < n; ++j)
        {
            double ra = items[idx[j]].second / items[idx[j]].first;
            double rb = items[idx[best]].second / items[idx[best]].first;
            if (ra > rb)
                best = j;
        }
        if (best != i)
        {
            int t = idx[i];
            idx[i] = idx[best];
            idx[best] = t;
        }
    }
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
    printf("%.4f\n", total);
    return 0;
}
