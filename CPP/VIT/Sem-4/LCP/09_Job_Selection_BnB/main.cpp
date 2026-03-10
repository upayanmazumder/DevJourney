#include <bits/stdc++.h>
using namespace std;
struct Job
{
    int id, d, p;
};
int n, maxD;
vector<Job> jobs;
vector<int> suffix;
int bestProfit = 0;
vector<int> bestSlots;
void solve(int idx, int currProfit, vector<int> &slots)
{
    if (idx == n)
    {
        if (currProfit > bestProfit)
        {
            bestProfit = currProfit;
            bestSlots = slots;
        }
        return;
    }
    if (currProfit + suffix[idx] <= bestProfit)
        return; // bound
    for (int s = min(maxD, jobs[idx].d); s >= 1; --s)
    {
        if (slots[s] == -1)
        {
            slots[s] = jobs[idx].id;
            solve(idx + 1, currProfit + jobs[idx].p, slots);
            slots[s] = -1;
        }
    }
    // try skipping
    solve(idx + 1, currProfit, slots);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!(cin >> n))
        return 0;
    jobs.resize(n);
    maxD = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> jobs[i].id >> jobs[i].d >> jobs[i].p;
        maxD = max(maxD, jobs[i].d);
    }
    sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b)
         { return a.p > b.p; });
    suffix.assign(n + 1, 0);
    for (int i = n - 1; i >= 0; --i)
        suffix[i] = suffix[i + 1] + jobs[i].p;
    vector<int> slots(maxD + 1, -1);
    solve(0, 0, slots);
    cout << bestProfit << "\n";
    for (int i = 1; i <= maxD; i++)
        if (bestSlots.size() > 0 && bestSlots[i] != -1)
            cout << "Slot " << i << ": Job " << bestSlots[i] << "\n";
    return 0;
}
