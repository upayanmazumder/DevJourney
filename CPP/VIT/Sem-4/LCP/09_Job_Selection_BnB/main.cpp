#include <iostream>
#include <vector>
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
    int startS = (maxD < jobs[idx].d) ? maxD : jobs[idx].d;
    for (int s = startS; s >= 1; --s)
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
    if (!(cin >> n))
        return 0;
    jobs.resize(n);
    maxD = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> jobs[i].id >> jobs[i].d >> jobs[i].p;
        if (jobs[i].d > maxD)
            maxD = jobs[i].d;
    }
    // simple selection sort by profit (descending) to avoid <algorithm>
    for (int i = 0; i < n; ++i)
    {
        int best = i;
        for (int j = i + 1; j < n; ++j)
            if (jobs[j].p > jobs[best].p)
                best = j;
        if (best != i)
        {
            Job tmp = jobs[i];
            jobs[i] = jobs[best];
            jobs[best] = tmp;
        }
    }
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
