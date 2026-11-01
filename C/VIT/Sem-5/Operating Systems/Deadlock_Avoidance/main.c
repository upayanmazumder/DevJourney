#include <stdbool.h>
#include <stdio.h>

int n, m;
int alloc[20][10], maxm[20][10], need[20][10], avail[10];

void show(char *t, int a[20][10]) {
    printf("%s\n", t);
    printf("PID\t");
    for (int j = 0; j < m; j++)
        printf("%c\t", 'A' + j);
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t", i);
        for (int j = 0; j < m; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
    printf("\n");
}

bool safe(int seq[]) {
    int work[10];
    bool fin[20] = {false};
    int c = 0;
    for (int j = 0; j < m; j++)
        work[j] = avail[j];
    while (c < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!fin[i]) {
                bool ok = true;
                for (int j = 0; j < m; j++)
                    if (need[i][j] > work[j]) {
                        ok = false;
                        break;
                    }
                if (ok) {
                    for (int j = 0; j < m; j++)
                        work[j] += alloc[i][j];
                    fin[i] = true;
                    seq[c++] = i;
                    found = true;
                }
            }
        }
        if (!found)
            return false;
    }
    return true;
}

int main() {
    printf("24BDS0367\tUpayan Mazumder\n\n");

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);

    printf("Enter Allocation matrix (%d rows of %d values):\n", n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Max matrix (%d rows of %d values):\n", n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &maxm[i][j]);

    printf("Enter Available vector (%d values): ", m);
    for (int j = 0; j < m; j++)
        scanf("%d", &avail[j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = maxm[i][j] - alloc[i][j];

    printf("\n");
    show("Need Matrix:", need);

    int seq[20];
    if (safe(seq)) {
        printf("System is in SAFE STATE\n");
        printf("Safe Sequence: ");
        for (int k = 0; k < n; k++) {
            printf("P%d", seq[k]);
            if (k < n - 1)
                printf(" -> ");
        }
        printf("\n\n");
    } else
        printf("System is in UNSAFE STATE\n\n");

    int p, req[10];
    printf("Enter process requesting (0 to %d): ", n - 1);
    scanf("%d", &p);
    printf("Enter request vector (%d values): ", m);
    for (int j = 0; j < m; j++)
        scanf("%d", &req[j]);
    printf("\n");

    printf("Request: P%d requests (", p);
    for (int j = 0; j < m; j++) {
        printf("%d", req[j]);
        if (j < m - 1)
            printf(", ");
    }
    printf(")\n\n");

    bool okNeed = true;
    for (int j = 0; j < m; j++)
        if (req[j] > need[p][j]) {
            okNeed = false;
            break;
        }
    if (!okNeed) {
        printf("Request cannot be GRANTED: Request > Need\n");
        return 0;
    }

    bool okAvail = true;
    for (int j = 0; j < m; j++)
        if (req[j] > avail[j]) {
            okAvail = false;
            break;
        }
    if (!okAvail) {
        printf("Request cannot be GRANTED: Request > Available\n");
        return 0;
    }

    for (int j = 0; j < m; j++) {
        avail[j] -= req[j];
        alloc[p][j] += req[j];
        need[p][j] -= req[j];
    }

    int nseq[20];
    if (safe(nseq)) {
        printf("Request can be GRANTED.\nSystem remains in SAFE STATE.\n\n");
        show("Updated Allocation:", alloc);
        show("Updated Need:", need);
        printf("Updated Available: ");
        for (int j = 0; j < m; j++)
            printf("%c=%d ", 'A' + j, avail[j]);
        printf("\n\n");
        printf("New Safe Sequence: ");
        for (int k = 0; k < n; k++) {
            printf("P%d", nseq[k]);
            if (k < n - 1)
                printf(" -> ");
        }
        printf("\n");
    } else {
        for (int j = 0; j < m; j++) {
            avail[j] += req[j];
            alloc[p][j] -= req[j];
            need[p][j] += req[j];
        }
        printf("Request cannot be GRANTED immediately: resulting state is UNSAFE\n");
    }
    return 0;
}
