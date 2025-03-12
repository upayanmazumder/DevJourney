#include <stdio.h>
#include <stdlib.h>

int maxDiff(int *A, int n) {
    int min = *A, max = *A;
    for(int i = 0; i < n; i ++) {
        if (*(A + i) > max) {
            max = *(A + i);
        }
        if (*(A + i) < min) {
            min = *(A + i);
        }
    }
    return max-min;
}

int main() {
    int N;
    scanf("%d", &N);
    int *p = (int *)malloc(N * sizeof(int));
    for(int i = 0; i < N; i++) {
        scanf("%d", p + i);
    }
    printf("%d", maxDiff(p,N));
}