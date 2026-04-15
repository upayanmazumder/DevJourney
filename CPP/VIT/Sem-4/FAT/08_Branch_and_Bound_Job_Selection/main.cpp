#include <iostream>

using namespace std;

const int MAX_JOBS = 20;
const int MAX_DEADLINE = 20;

struct Job
{
    int id;
    int deadline;
    int profit;
};

int n;
int maxDeadline = 0;
Job jobs[MAX_JOBS];
int slotUsed[MAX_DEADLINE + 1];
int currentChosen[MAX_JOBS];
int bestChosen[MAX_JOBS];
int bestProfit = 0;

void sortJobsByProfitDesc(Job jobsArr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (jobsArr[j].profit < jobsArr[j + 1].profit)
            {
                Job temp = jobsArr[j];
                jobsArr[j] = jobsArr[j + 1];
                jobsArr[j + 1] = temp;
            }
        }
    }
}

int calculateBound(int level, int currentProfit)
{
    int optimisticProfit = currentProfit;
    int tempSlot[MAX_DEADLINE + 1];

    for (int t = 1; t <= maxDeadline; t++)
    {
        tempSlot[t] = slotUsed[t];
    }

    for (int i = level; i < n; i++)
    {
        int latest = jobs[i].deadline;

        if (latest > maxDeadline)
        {
            latest = maxDeadline;
        }

        for (int t = latest; t >= 1; t--)
        {
            if (tempSlot[t] == 0)
            {
                tempSlot[t] = 1;
                optimisticProfit += jobs[i].profit;
                break;
            }
        }
    }

    return optimisticProfit;
}

void solve(int level, int currentProfit)
{
    if (level == n)
    {
        if (currentProfit > bestProfit)
        {
            bestProfit = currentProfit;
            for (int i = 0; i < n; i++)
            {
                bestChosen[i] = currentChosen[i];
            }
        }
        return;
    }

    int bound = calculateBound(level, currentProfit);
    if (bound <= bestProfit)
    {
        return;
    }

    int latest = jobs[level].deadline;
    if (latest > maxDeadline)
    {
        latest = maxDeadline;
    }

    // Include this job if a slot is available.
    for (int t = latest; t >= 1; t--)
    {
        if (slotUsed[t] == 0)
        {
            slotUsed[t] = 1;
            currentChosen[level] = 1;
            solve(level + 1, currentProfit + jobs[level].profit);
            currentChosen[level] = 0;
            slotUsed[t] = 0;
            break;
        }
    }

    // Exclude this job.
    currentChosen[level] = 0;
    solve(level + 1, currentProfit);
}

int main()
{
    cout << "Enter number of jobs (max " << MAX_JOBS << "): ";
    cin >> n;

    if (n <= 0 || n > MAX_JOBS)
    {
        cout << "Invalid number of jobs.\n";
        return 0;
    }

    cout << "Enter each job as: id deadline profit\n";
    for (int i = 0; i < n; i++)
    {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
        if (jobs[i].deadline > maxDeadline)
        {
            maxDeadline = jobs[i].deadline;
        }
    }

    if (maxDeadline > MAX_DEADLINE)
    {
        maxDeadline = MAX_DEADLINE;
    }

    sortJobsByProfitDesc(jobs, n);

    for (int t = 1; t <= maxDeadline; t++)
    {
        slotUsed[t] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        currentChosen[i] = 0;
        bestChosen[i] = 0;
    }

    bestProfit = 0;
    solve(0, 0);

    cout << "Maximum Profit = " << bestProfit << "\n";
    cout << "Selected Jobs (id, deadline, profit):\n";

    bool any = false;
    for (int i = 0; i < n; i++)
    {
        if (bestChosen[i] == 1)
        {
            cout << jobs[i].id << " " << jobs[i].deadline << " " << jobs[i].profit << "\n";
            any = true;
        }
    }

    if (!any)
    {
        cout << "No jobs selected.\n";
    }

    return 0;
}
