#include <stdio.h>
#include <stdlib.h>

int main() {
    int *N = (int *)malloc(sizeof(int));
    scanf("%d",N);
    int *A = (int *)malloc(*N *sizeof(int));
    int *B = (int *)malloc(*N *sizeof(int));
    for (int i =0; i < *N; i++) {
        scanf("%d", A + i);
    }
    for (int i = 0; i < *N; i++) {
        scanf("%d", B + i);
    }
    for (int i = 0; i < *N; i++) {
        if(*(B + i ) == 1) {
            *(A + i) = ( -1 ) * (*(A + i));
        }
    }
    for (int i = 0; i < *N; i++) {
        printf("%d ", *(A + i));
    }
}