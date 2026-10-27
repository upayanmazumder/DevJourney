#include <limits.h>
#include <stdio.h>

typedef struct {
    int pid;
    int at;
    int bt;
    int rt;
    int ct;
    int tat;
    int wt;
} Process;

typedef struct {
    int pid;
    int start;
    int end;
} Gantt;

int main() {
    int n;

    printf("24BDS0367\tUpayan Mazumder\n\n");
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Process %d\n", i + 1);
        printf("Process ID: ");
        scanf("%d", &p[i].pid);
        printf("Arrival Time: ");
        scanf("%d", &p[i].at);
        printf("Burst Time: ");
        scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt;
        p[i].ct = 0;
        p[i].tat = 0;
        p[i].wt = 0;
    }

    Gantt gantt[1000];
    int ganttCount = 0;
    int completed = 0;
    int time = 0;

    while (completed < n) {
        int selected = -1;
        int shortest = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rt > 0) {
                if (p[i].rt < shortest) {
                    shortest = p[i].rt;
                    selected = i;
                }

                else if (p[i].rt == shortest && p[i].pid < p[selected].pid) {
                    selected = i;
                }
            }
        }

        if (selected == -1) {
            int start = time;
            int nextArrival = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (p[i].rt > 0 && p[i].at > time) {
                    if (p[i].at < nextArrival)
                        nextArrival = p[i].at;
                }
            }
            time = nextArrival;
            gantt[ganttCount].pid = -1;
            gantt[ganttCount].start = start;
            gantt[ganttCount].end = time;
            ganttCount++;
            continue;
        }

        int start = time;

        p[selected].rt--;

        time++;
        if (p[selected].rt == 0) {
            p[selected].ct = time;
            completed++;
        }

        if (ganttCount > 0 && gantt[ganttCount - 1].pid == p[selected].pid &&
            gantt[ganttCount - 1].end == start) {
            gantt[ganttCount - 1].end = time;
        } else {
            gantt[ganttCount].pid = p[selected].pid;
            gantt[ganttCount].start = start;
            gantt[ganttCount].end = time;
            ganttCount++;
        }
    }

    float totalWT = 0;
    float totalTAT = 0;
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        totalWT += p[i].wt;
        totalTAT += p[i].tat;
    }

    printf("\n\nGantt Chart:\n");
    printf(" ");
    for (int i = 0; i < ganttCount; i++) {
        printf("-------");
    }
    printf("\n|");
    for (int i = 0; i < ganttCount; i++) {
        if (gantt[i].pid == -1)
            printf(" IDLE |");
        else
            printf(" P%d |", gantt[i].pid);
    }
    printf("\n ");
    for (int i = 0; i < ganttCount; i++) {
        printf("-------");
    }
    printf("\n%d", gantt[0].start);
    for (int i = 0; i < ganttCount; i++) {
        printf("%7d", gantt[i].end);
    }

    printf("\n\nProcess Table:\n");
    printf("+-----+----+----+----+-----+----+\n");
    printf("| PID | AT | BT | CT | TAT | WT |\n");
    printf("+-----+----+----+----+-----+----+\n");
    for (int i = 0; i < n; i++) {
        printf("| P%-2d | %-2d | %-2d | %-2d | %-3d | %-2d |\n", p[i].pid, p[i].at, p[i].bt,
               p[i].ct, p[i].tat, p[i].wt);
    }
    printf("+-----+----+----+----+-----+----+\n");
    printf("\nAverage Waiting Time = %.2f\n", totalWT / n);
    printf("Average Turnaround Time = %.2f\n", totalTAT / n);

    for (int i = 0; i < n; i++) {
        if (p[i].pid == 3) {
            printf("Completion Time of P3 = %d\n", p[i].ct);
            break;
        }
    }
    return 0;
}
