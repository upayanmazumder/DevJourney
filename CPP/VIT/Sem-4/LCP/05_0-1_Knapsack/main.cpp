#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, W;
    if (!(cin >> n >> W))
        return 0;
    vector<int> wt(n), val(n);
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    for (int i = 0; i < n; i++)
        cin >> val[i];
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int w = 0; w <= W; w++)
        {
            dp[i][w] = dp[i - 1][w];
            if (wt[i - 1] <= w)
                dp[i][w] = max(dp[i][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
        }
    cout << dp[n][W] << "\n";
    int w = W;
    vector<int> items;
    for (int i = n; i >= 1; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            items.push_back(i - 1);
            w -= wt[i - 1];
        }
    }
    reverse(items.begin(), items.end());
    for (int id : items)
        cout << id << " ";
    cout << "\n";
    return 0;
}
