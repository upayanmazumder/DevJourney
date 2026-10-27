#include <stdio.h>

struct Process {
    int pid, at, bt, ct, tat, wt;
};

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    printf("Enter arrival time and burst time for each process: \n");
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Process %d:\t", i + 1);
        scanf("%d %d", &p[i].at, &p[i].bt);
    }

    // Sort by arrival time (FCFS)
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (p[j].at > p[j + 1].at) {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }

    int current_time = 0;
    printf("Gantt Chart:\n|");
    for (int i = 0; i < n; i++) {
        if (current_time < p[i].at)
            current_time = p[i].at;

        printf(" P%d |", p[i].pid);
        current_time += p[i].bt;
        p[i].ct = current_time;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }
    printf("\n");

    printf("\n%-5s%-5s%-5s%-5s%-5s%-5s\n", "PID", "AT", "BT", "CT", "TAT", "WT");
    float total_wt = 0, total_tat = 0;
    int ct_p3 = 0;
    for (int i = 0; i < n; i++) {
        printf("%-5d%-5d%-5d%-5d%-5d%-5d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat,
               p[i].wt);
        total_wt += p[i].wt;
        total_tat += p[i].tat;
        if (p[i].pid == 3)
            ct_p3 = p[i].ct;
    }

    printf("Average waiting time = %.2f\n", total_wt / n);
    printf("Average turnaround time = %.2f\n", total_tat / n);
    printf("Completion time of process P3 = %d\n", ct_p3);

    return 0;
}
