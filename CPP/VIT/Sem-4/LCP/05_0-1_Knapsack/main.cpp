#include <iostream>
#include <vector>
using namespace std;
int main()
{

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
            {
                int cand = dp[i - 1][w - wt[i - 1]] + val[i - 1];
                if (cand > dp[i][w])
                    dp[i][w] = cand;
            }
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
    for (int k = (int)items.size() - 1; k >= 0; --k)
        cout << items[k] << " ";
    cout << "\n";
    return 0;
}
