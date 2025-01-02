#include <stdio.h>

int main() {
    int temp, a[20], i, j, k, n, x;

    printf("How many numbers: ");
    scanf("%d", &n);

    printf("Enter the numbers: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int uniqueCount = n;
    for (i = 0; i < uniqueCount; i++) {
        for (j = i + 1; j < uniqueCount; j++) {
            if (a[i] == a[j]) {
                for (k = j; k < uniqueCount - 1; k++) {
                    a[k] = a[k + 1];
                }
                uniqueCount--;
                j--;
            }
        }
    }

    for (j = 0; j < uniqueCount - 1; j++) {
        for (k = j + 1; k < uniqueCount; k++) {
            if (a[j] > a[k]) {
                temp = a[j];
                a[j] = a[k];
                a[k] = temp;
            }
        }
    }

    printf("\nEnter the value of k: ");
    scanf("%d", &x);

    if (x > 0 && x <= uniqueCount) {
        printf("The %dth smallest element is %d", x, a[x - 1]);
    } else {
        printf("Invalid value of k");
    }
}