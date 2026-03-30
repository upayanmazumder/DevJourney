#include <iostream>
using namespace std;

struct Job
{
    int id, d, p;
};

int main()
{
    int n;
    cin >> n;

    Job jobs[100];
    int maxD = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> jobs[i].id >> jobs[i].d >> jobs[i].p;
        if (jobs[i].d > maxD)
            maxD = jobs[i].d;
    }

    // sort jobs by profit (descending)
    for (int i = 0; i < n; i++)
    {
        int best = i;
        for (int j = i + 1; j < n; j++)
        {
            if (jobs[j].p > jobs[best].p)
                best = j;
        }

        if (best != i)
        {
            Job temp = jobs[i];
            jobs[i] = jobs[best];
            jobs[best] = temp;
        }
    }

    int slots[100];
    for (int i = 1; i <= maxD; i++)
        slots[i] = -1;

    int totalProfit = 0;

    // schedule jobs
    for (int i = 0; i < n; i++)
    {
        for (int s = jobs[i].d; s >= 1; s--)
        {
            if (slots[s] == -1)
            {
                slots[s] = jobs[i].id;
                totalProfit += jobs[i].p;
                break;
            }
        }
    }

    cout << totalProfit << endl;

    for (int i = 1; i <= maxD; i++)
    {
        if (slots[i] != -1)
            cout << "Slot " << i << ": Job " << slots[i] << endl;
    }

    return 0;
}