#include <stdio.h>
#include <string.h>
#define MAX 100

struct Process {
    char pid[10];
    int at, bt, priority;
    int remaining, ct, tat, wt;
};

int main() {
    struct Process p[MAX];
    int n, time = 0, completed = 0;
    float avgWT = 0, avgTAT = 0;

    printf("24BDS0367\tUpayan Mazumder\n\n");

    printf("Enter number of processes: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX) {
        printf("Invalid number of processes.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter PID, Arrival Time, Burst Time, Priority for P%d: ", i + 1);
        scanf("%9s %d %d %d", p[i].pid, &p[i].at, &p[i].bt, &p[i].priority);
        p[i].remaining = p[i].bt;
        p[i].ct = p[i].tat = p[i].wt = 0;
    }

    printf("\nGantt Chart:\n");

    int current = -1;
    int start = 0;

    while (completed < n) {
        int selected = -1;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].remaining > 0) {
                if (selected == -1 || p[i].priority > p[selected].priority ||
                    (p[i].priority == p[selected].priority &&
                     strcmp(p[i].pid, p[selected].pid) < 0)) {
                    selected = i;
                }
            }
        }
        if (selected == -1) {
            if (current != -2) {
                if (current >= 0)
                    printf("| %s (%d-%d) ", p[current].pid, start, time);
                printf("| IDLE ");
                start = time;
                current = -2;
            }
            time++;
            continue;
        }

        if (selected != current) {
            if (current >= 0)
                printf("| %s (%d-%d) ", p[current].pid, start, time);
            start = time;
            current = selected;
        }

        p[selected].remaining--;
        time++;

        if (p[selected].remaining == 0) {
            p[selected].ct = time;
            p[selected].tat = p[selected].ct - p[selected].at;
            p[selected].wt = p[selected].tat - p[selected].bt;
            completed++;
        }
    }

    if (current >= 0)
        printf("| %s (%d-%d) ", p[current].pid, start, time);
    else if (current == -2)
        printf("| IDLE (%d-%d) ", start, time);
    printf("|\n");

    printf("\nPID\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].priority, p[i].ct,
               p[i].tat, p[i].wt);
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
