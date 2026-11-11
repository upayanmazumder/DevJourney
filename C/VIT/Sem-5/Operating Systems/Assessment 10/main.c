#include <limits.h>
#include <stdio.h>

struct Process {
    int pid;
    int at;
    int bt;
    int rt;
    int ct;
    int tat;
    int wt;
};

int main(void) {
    int n;
    printf("Registration Number: 24BDS0367\n");
    printf("Name: Upayan Mazumder\n");
    printf("Operating Systems Lab Assessment 10\n\n");

    printf("Enter number of processes: ");
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    if (n <= 0) {
        return 1;
    }

    struct Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time for P%d: ", i + 1);
        scanf("%d", &p[i].at);
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt;
    }

    int completed = 0, current_time = 0;
    while (completed < n) {
        int idx = -1, min_rt = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= current_time && p[i].rt > 0) {
                if (p[i].rt < min_rt) {
                    min_rt = p[i].rt;
                    idx = i;
                } else if (p[i].rt == min_rt && p[i].at < p[idx].at) {
                    idx = i;
                }
            }
        }
        if (idx != -1) {
            p[idx].rt--;
            current_time++;
            if (p[idx].rt == 0) {
                p[idx].ct = current_time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                completed++;
            }
        } else {
            current_time++;
        }
    }

    float total_tat = 0.0f, total_wt = 0.0f;
    printf("\n--------------------------------------------------------------------------------\n");
    printf("%-8s %-14s %-12s %-18s %-18s %-14s\n", "Process", "Arrival Time", "Burst Time",
           "Completion Time", "Turnaround Time", "Waiting Time");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        total_tat += p[i].tat;
        total_wt += p[i].wt;
        printf("P%-7d %-14d %-12d %-18d %-18d %-14d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct,
               p[i].tat, p[i].wt);
    }
    printf("--------------------------------------------------------------------------------\n");
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
    printf("Average Waiting Time = %.2f\n", total_wt / n);
    return 0;
}
