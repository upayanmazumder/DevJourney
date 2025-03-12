#include<stdio.h>
#include<stdlib.h>

int countInRange(int *arr, int n, int lower, int upper) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (*(arr + i) >= lower && *(arr + i) <= upper ) {
            count++;
        }
    }
    return count;
}

int main() {
    int n, lower, upper;
    scanf("%d", &n);
    int *inventory = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", (inventory + i));
    }
    scanf("%d %d", &lower, &upper);
    int result = countInRange(inventory, n, lower, upper);
    printf("%d\n", result);
    free(inventory);
}