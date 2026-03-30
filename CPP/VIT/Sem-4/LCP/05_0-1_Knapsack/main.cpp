#include <iostream>
using namespace std;

int main()
{
    int n, W;

    if (!(cin >> n >> W))
        return 0;

    int wt[100], val[100];

    // Read weights
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    // Read values
    for (int i = 0; i < n; i++)
        cin >> val[i];

    int dp[101][101] = {0};

    // Build DP table
    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            dp[i][w] = dp[i - 1][w];

            if (wt[i - 1] <= w)
            {
                int candidate = dp[i - 1][w - wt[i - 1]] + val[i - 1];

                if (candidate > dp[i][w])
                    dp[i][w] = candidate;
            }
        }
    }

    cout << dp[n][W] << endl;

    // Trace back selected items
    int w = W;
    int items[100];
    int count = 0;

    for (int i = n; i >= 1; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            items[count++] = i - 1;
            w -= wt[i - 1];
        }
    }

    // Print items in correct order
    for (int i = count - 1; i >= 0; i--)
        cout << items[i] << " ";

    cout << endl;

    return 0;
}