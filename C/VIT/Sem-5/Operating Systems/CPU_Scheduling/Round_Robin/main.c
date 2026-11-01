#include <stdio.h>
#include <string.h>
#define MAX 100
#define QUEUE_SIZE 10000

struct Process {
    char pid[10];
    int at, bt;
    int remaining, ct, tat, wt;
};

int main() {
    struct Process p[MAX];
    int n, time = 0, completed = 0;
    int quantum = 2;
    int queue[QUEUE_SIZE];
    int front = 0, rear = 0;
    int added[MAX] = {0};
    float avgWT = 0, avgTAT = 0;

    printf("24BDS0367\tUpayan Mazumder\n\n");

    printf("Enter number of processes: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of processes.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter PID, Arrival Time, Burst Time for P%d: ", i + 1);
        scanf("%9s %d %d", p[i].pid, &p[i].at, &p[i].bt);
        p[i].remaining = p[i].bt;
        p[i].ct = p[i].tat = p[i].wt = 0;
    }

    printf("\nGantt Chart:\n");

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (!added[i] && p[i].at <= time) {
                queue[rear++] = i;
                added[i] = 1;
            }
        }

        if (front == rear) {
            printf("| IDLE (%d-%d) ", time, time + 1);
            time++;
            continue;
        }

        int current = queue[front++];
        int start = time;
        int execute = p[current].remaining < quantum ? p[current].remaining : quantum;
        p[current].remaining -= execute;
        time += execute;
        printf("| %s (%d-%d) ", p[current].pid, start, time);

        for (int i = 0; i < n; i++) {
            if (!added[i] && p[i].at <= time) {
                queue[rear++] = i;
                added[i] = 1;
            }
        }

        if (p[current].remaining == 0) {
            p[current].ct = time;
            p[current].tat = p[current].ct - p[current].at;
            p[current].wt = p[current].tat - p[current].bt;
            completed++;
        } else {
            queue[rear++] = current;
        }
    }
    printf("|\n");
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
        avgWT += p[i].wt;
        avgTAT += p[i].tat;
    }
    printf("\nAverage Waiting Time = %.2f\n", avgWT / n);
    printf("Average Turnaround Time = %.2f\n", avgTAT / n);
    for (int i = 0; i < n; i++) {
        if (strcmp(p[i].pid, "P4") == 0) {
            printf("Completion Time of Process P4 = %d\n", p[i].ct);
            break;
        }
    }
    return 0;
}
