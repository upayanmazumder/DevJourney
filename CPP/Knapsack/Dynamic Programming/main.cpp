#include <iostream>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, W;
    cin >> n >> W;

    int wt[100], val[100];
    int dp[101][101];

    for (int i = 0; i < n; i++)
        cin >> wt[i];

    for (int i = 0; i < n; i++)
        cin >> val[i];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i-1] <= w)
                dp[i][w] = max(
                    dp[i-1][w], val[i-1] + dp[i-1][w - wt[i-1]]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    cout << dp[n][W];
    return 0;
}
