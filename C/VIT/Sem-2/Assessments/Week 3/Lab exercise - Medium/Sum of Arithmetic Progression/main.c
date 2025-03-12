#include <stdio.h>

int calculateAPSum(int *a1, int *d, int *n) {
    return ((*n) * (2 * (*a1) + ((*n) - 1) * (*d))) / 2;
}

int main() {
    int a1, d, n;
    scanf("%d %d %d", &a1, &d, &n);
    int sum = calculateAPSum(&a1, &d, &n);
    printf("%d", sum);
}