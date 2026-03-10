#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n))
        return 0;
    vector<int> e(2), x(2);
    cin >> e[0] >> e[1];
    cin >> x[0] >> x[1];
    vector<int> a1(n), a2(n);
    for (int i = 0; i < n; i++)
        cin >> a1[i];
    for (int i = 0; i < n; i++)
        cin >> a2[i];
    vector<int> t1(max(0, n - 1)), t2(max(0, n - 1));
    for (int i = 0; i < n - 1; i++)
        cin >> t1[i];
    for (int i = 0; i < n - 1; i++)
        cin >> t2[i];
    vector<int> f1(n), f2(n), from1(n), from2(n);
    f1[0] = e[0] + a1[0];
    f2[0] = e[1] + a2[0];
    for (int i = 1; i < n; i++)
    {
        if (f1[i - 1] + a1[i] <= f2[i - 1] + t2[i - 1] + a1[i])
        {
            f1[i] = f1[i - 1] + a1[i];
            from1[i] = 0;
        }
        else
        {
            f1[i] = f2[i - 1] + t2[i - 1] + a1[i];
            from1[i] = 1;
        }
        if (f2[i - 1] + a2[i] <= f1[i - 1] + t1[i - 1] + a2[i])
        {
            f2[i] = f2[i - 1] + a2[i];
            from2[i] = 1;
        }
        else
        {
            f2[i] = f1[i - 1] + t1[i - 1] + a2[i];
            from2[i] = 0;
        }
    }
    int bestLine;
    int bestTime1 = f1[n - 1] + x[0];
    int bestTime2 = f2[n - 1] + x[1];
    if (bestTime1 <= bestTime2)
    {
        cout << bestTime1 << "\n";
        bestLine = 0;
    }
    else
    {
        cout << bestTime2 << "\n";
        bestLine = 1;
    }
    vector<int> path(n);
    path[n - 1] = bestLine;
    for (int i = n - 1; i > 0; i--)
    {
        path[i - 1] = (path[i] == 0) ? from1[i] : from2[i];
    }
    for (int i = 0; i < n; i++)
        cout << "Station " << i + 1 << ": Line " << path[i] + 1 << "\n";
    return 0;
}