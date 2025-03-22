#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n, *arr, sum = 0;
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("Sum = %d", sum);
    free(arr);
    printf("\nFreed memory!");
}