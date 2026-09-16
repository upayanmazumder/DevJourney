// 24BDS0367 Upayan Mazumder

#include <stdio.h>

#define MAX_P 20
#define MAX_R 10

int P;
int R;

int allocation[MAX_P][MAX_R];
int maximum[MAX_P][MAX_R];
int available[MAX_R];
int need[MAX_P][MAX_R];

void readInput(void)
{
    printf("Enter number of processes: ");
    scanf("%d", &P);
    printf("Enter number of resource types: ");
    scanf("%d", &R);

    printf("\nEnter the Allocation matrix (%d x %d):\n", P, R);
    for (int i = 0; i < P; i++)
    {
        printf("P%d: ", i);
        for (int j = 0; j < R; j++)
            scanf("%d", &allocation[i][j]);
    }

    printf("\nEnter the Maximum matrix (%d x %d):\n", P, R);
    for (int i = 0; i < P; i++)
    {
        printf("P%d: ", i);
        for (int j = 0; j < R; j++)
            scanf("%d", &maximum[i][j]);
    }

    printf("\nEnter the Available resource vector (%d values):\n", R);
    for (int j = 0; j < R; j++)
        scanf("%d", &available[j]);
}

void calculateNeed(void)
{
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = maximum[i][j] - allocation[i][j];
}

void printNeed(void)
{
    printf("\nNeed Matrix:\n");
    printf("PID\t");
    for (int j = 0; j < R; j++)
        printf("%c\t", 'A' + j);
    printf("\n");

    for (int i = 0; i < P; i++)
    {
        printf("P%d\t", i);
        for (int j = 0; j < R; j++)
            printf("%d\t", need[i][j]);
        printf("\n");
    }
}

void printAllocation(void)
{
    printf("\nAllocation Matrix:\n");
    printf("PID\t");
    for (int j = 0; j < R; j++)
        printf("%c\t", 'A' + j);
    printf("\n");

    for (int i = 0; i < P; i++)
    {
        printf("P%d\t", i);
        for (int j = 0; j < R; j++)
            printf("%d\t", allocation[i][j]);
        printf("\n");
    }
}

void printAvailable(void)
{
    printf("\nAvailable Resources: ");
    for (int j = 0; j < R; j++)
        printf("%d ", available[j]);
    printf("\n");
}

int isSafe(int safeSeq[MAX_P])
{
    int work[MAX_R];
    int finish[MAX_P] = {0};

    for (int j = 0; j < R; j++)
        work[j] = available[j];

    int count = 0;
    while (count < P)
    {
        int found = 0;

        for (int i = 0; i < P; i++)
        {
            if (finish[i])
                continue;

            int canRun = 1;
            for (int j = 0; j < R; j++)
            {
                if (need[i][j] > work[j])
                {
                    canRun = 0;
                    break;
                }
            }

            if (canRun)
            {
                for (int j = 0; j < R; j++)
                    work[j] += allocation[i][j];

                safeSeq[count++] = i;
                finish[i] = 1;
                found = 1;
            }
        }

        if (!found)
            break;
    }

    return count == P;
}

void printSafeSequence(int safeSeq[MAX_P])
{
    printf("Safe Sequence: ");
    for (int i = 0; i < P; i++)
    {
        printf("P%d", safeSeq[i]);
        if (i != P - 1)
            printf(" -> ");
    }
    printf("\n");
}

int requestResources(int pid, int request[MAX_R])
{
    for (int j = 0; j < R; j++)
    {
        if (request[j] > need[pid][j])
        {
            printf("\nError: Request exceeds the process's declared Need.\n");
            printf("Request cannot be GRANTED.\n");
            return 0;
        }
    }

    for (int j = 0; j < R; j++)
    {
        if (request[j] > available[j])
        {
            printf("\nRequest cannot be GRANTED. Not enough Available resources.\n");
            return 0;
        }
    }

    for (int j = 0; j < R; j++)
    {
        available[j] -= request[j];
        allocation[pid][j] += request[j];
        need[pid][j] -= request[j];
    }

    int safeSeq[MAX_P];
    if (isSafe(safeSeq))
    {
        printf("\nRequest can be GRANTED. System remains in SAFE STATE.\n");
        printAllocation();
        printNeed();
        printAvailable();
        printSafeSequence(safeSeq);
        return 1;
    }
    else
    {
        for (int j = 0; j < R; j++)
        {
            available[j] += request[j];
            allocation[pid][j] -= request[j];
            need[pid][j] += request[j];
        }
        printf("\nRequest cannot be GRANTED immediately. Granting it would leave the system in an UNSAFE STATE.\n");
        return 0;
    }
}

int main(void)
{
    printf("24BDS0367 Upayan Mazumder\n\n");

    readInput();

    calculateNeed();
    printNeed();

    int safeSeq[MAX_P];
    if (isSafe(safeSeq))
    {
        printf("\nSystem is in SAFE STATE\n");
        printSafeSequence(safeSeq);
    }
    else
    {
        printf("\nSystem is in UNSAFE STATE\n");
    }

    int pid;
    int request[MAX_R];

    printf("\nEnter the process number making the additional request (0 to %d): ", P - 1);
    scanf("%d", &pid);

    printf("Enter the request vector (%d values): ", R);
    for (int j = 0; j < R; j++)
        scanf("%d", &request[j]);

    printf("\nAdditional Request: P%d requests: (", pid);
    for (int j = 0; j < R; j++)
        printf("%d%s", request[j], (j != R - 1) ? ", " : "");
    printf(")\n");

    requestResources(pid, request);

    return 0;
}
