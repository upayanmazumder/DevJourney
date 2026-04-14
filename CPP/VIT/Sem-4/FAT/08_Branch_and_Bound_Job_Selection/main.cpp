#include <iostream>

using namespace std;

const int MAX_JOBS = 50;
const int MAX_NODES = 10000;

struct Job
{
    int id;
    int deadline;
    int profit;
};

struct Node
{
    int level;
    int profit;
    int bound;
    int slotOwner[MAX_JOBS + 1]; // slotOwner[t] = job index in sorted array, -1 if free
    int chosen[MAX_JOBS];        // chosen[i] = 1 if job i selected, else 0
};

void copyNode(Node &to, const Node &from, int n, int maxDeadline)
{
    to.level = from.level;
    to.profit = from.profit;
    to.bound = from.bound;

    for (int i = 0; i < n; i++)
    {
        to.chosen[i] = from.chosen[i];
    }
    for (int t = 1; t <= maxDeadline; t++)
    {
        to.slotOwner[t] = from.slotOwner[t];
    }
}

void sortJobsByProfitDesc(Job *jobs, int n)
{
    // Bubble sort to avoid <algorithm>.
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (jobs[j].profit < jobs[j + 1].profit)
            {
                Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}

int calculateBound(const Node &node, Job *jobs, int n, int maxDeadline)
{
    int optimisticProfit = node.profit;

    int tempSlots[MAX_JOBS + 1];
    for (int t = 1; t <= maxDeadline; t++)
    {
        tempSlots[t] = node.slotOwner[t];
    }

    // Greedy fill with remaining jobs to get an upper bound.
    for (int i = node.level + 1; i < n; i++)
    {
        int latest = jobs[i].deadline;
        if (latest > maxDeadline)
            latest = maxDeadline;

        for (int t = latest; t >= 1; t--)
        {
            if (tempSlots[t] == -1)
            {
                tempSlots[t] = i;
                optimisticProfit += jobs[i].profit;
                break;
            }
        }
    }

    return optimisticProfit;
}

bool tryScheduleJob(Node &node, int jobIndex, Job *jobs, int maxDeadline)
{
    int latest = jobs[jobIndex].deadline;
    if (latest > maxDeadline)
        latest = maxDeadline;

    // Place the job in latest free slot <= deadline.
    for (int t = latest; t >= 1; t--)
    {
        if (node.slotOwner[t] == -1)
        {
            node.slotOwner[t] = jobIndex;
            node.profit += jobs[jobIndex].profit;
            node.chosen[jobIndex] = 1;
            return true;
        }
    }

    return false;
}

int extractMaxBoundNode(Node *pq, int &pqSize)
{
    int bestIdx = 0;
    for (int i = 1; i < pqSize; i++)
    {
        if (pq[i].bound > pq[bestIdx].bound)
        {
            bestIdx = i;
        }
    }

    Node temp = pq[bestIdx];
    pq[bestIdx] = pq[pqSize - 1];
    pq[pqSize - 1] = temp;

    pqSize--;
    return pqSize; // index of extracted node after swap is pqSize
}

int main()
{
    int n;
    cout << "Enter number of jobs (max " << MAX_JOBS << "): ";
    cin >> n;

    if (n <= 0 || n > MAX_JOBS)
    {
        cout << "Invalid number of jobs.\n";
        return 0;
    }

    Job jobs[MAX_JOBS];
    int maxDeadline = 0;

    cout << "Enter each job as: id deadline profit\n";
    for (int i = 0; i < n; i++)
    {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
        if (jobs[i].deadline > maxDeadline)
        {
            maxDeadline = jobs[i].deadline;
        }
    }

    if (maxDeadline > MAX_JOBS)
    {
        maxDeadline = MAX_JOBS;
    }

    sortJobsByProfitDesc(jobs, n);

    Node bestNode;
    bestNode.level = -1;
    bestNode.profit = 0;
    bestNode.bound = 0;
    for (int i = 0; i < n; i++)
    {
        bestNode.chosen[i] = 0;
    }
    for (int t = 1; t <= maxDeadline; t++)
    {
        bestNode.slotOwner[t] = -1;
    }

    Node root = bestNode;
    root.bound = calculateBound(root, jobs, n, maxDeadline);

    Node pq[MAX_NODES];
    int pqSize = 0;
    pq[pqSize++] = root;

    int bestProfit = 0;

    while (pqSize > 0)
    {
        int extractedIndex = extractMaxBoundNode(pq, pqSize);
        Node current = pq[extractedIndex];

        if (current.bound <= bestProfit)
        {
            continue;
        }

        int nextLevel = current.level + 1;
        if (nextLevel >= n)
        {
            continue;
        }

        // Include next job branch.
        Node includeNode;
        copyNode(includeNode, current, n, maxDeadline);
        includeNode.level = nextLevel;

        if (tryScheduleJob(includeNode, nextLevel, jobs, maxDeadline))
        {
            includeNode.bound = calculateBound(includeNode, jobs, n, maxDeadline);

            if (includeNode.profit > bestProfit)
            {
                bestProfit = includeNode.profit;
                copyNode(bestNode, includeNode, n, maxDeadline);
            }

            if (includeNode.bound > bestProfit && pqSize < MAX_NODES)
            {
                pq[pqSize++] = includeNode;
            }
        }

        // Exclude next job branch.
        Node excludeNode;
        copyNode(excludeNode, current, n, maxDeadline);
        excludeNode.level = nextLevel;
        excludeNode.chosen[nextLevel] = 0;
        excludeNode.bound = calculateBound(excludeNode, jobs, n, maxDeadline);

        if (excludeNode.bound > bestProfit && pqSize < MAX_NODES)
        {
            pq[pqSize++] = excludeNode;
        }
    }

    cout << "Maximum Profit = " << bestProfit << "\n";
    cout << "Selected Jobs (id, deadline, profit):\n";

    bool any = false;
    for (int i = 0; i < n; i++)
    {
        if (bestNode.chosen[i] == 1)
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
