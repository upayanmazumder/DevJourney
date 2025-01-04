#include<stdio.h>

int main() {
    int i, j, n, a[100], unique[100], uniqueN = 0, found;

    printf("How many numbers: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter %dth element: ", i + 1);
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++) {
        found = 0;
        for (j = 0; j < uniqueN; j++) {
            if (a[i] == unique[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            unique[uniqueN] = a[i];
            uniqueN++;
        }
    }

    printf("Array without duplicates: ");
    for (i = 0; i < uniqueN; i++) {
        printf("%d ", unique[i]);
    }
}
