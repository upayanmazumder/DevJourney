#include <stdio.h>
#include <stdlib.h>
int main() {
    int *N = (int *)malloc(sizeof(int));
    scanf("%d",N);
    int *A = (int *)malloc(*N*sizeof(int));
    int *P = (int *)malloc(sizeof(int));
    *P = 1;
    for (int i = 0; i < *N; i++) {
        scanf("%d", A+i);
        *P = (*P) * (*(A + i));
    }
    for (int i = 0; i < *N; i++) {
        *(A + i) = (*P) / (*(A + i));
    }
    for (int i = 0; i < *N; i++) {
        printf("%d ", *(A + i));
    }
}