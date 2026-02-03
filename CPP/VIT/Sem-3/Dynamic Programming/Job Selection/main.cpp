#include <iostream>
using namespace std;

struct Job {
    int deadline;
    int time;
    int profit;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n;
    cin >> n;

    Job jobs[100];   
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].deadline >> jobs[i].time >> jobs[i].profit;
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (jobs[j].deadline > jobs[j + 1].deadline) {
                Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
    
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    int dp[1000] = {0}; 

    for (int i = 0; i < n; i++) {
        for (int t = jobs[i].deadline; t >= jobs[i].time; t--) {
            dp[t] = max(dp[t], dp[t - jobs[i].time] + jobs[i].profit);
        }
    }
    
    int ans = 0;
    for (int i = 0; i <= maxDeadline; i++) {
        if (dp[i] > ans)
            ans = dp[i];
    }

    cout << ans << endl;
    return 0;
}
