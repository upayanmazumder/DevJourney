#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    while (b != 0 ) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int *N = (int *)malloc(sizeof(int));
    scanf("%d", N);
    int *A = (int *)malloc(30 * sizeof(int));
    int *sum = (int *)malloc(sizeof(int));
    *sum = 0;
    for (int i = 1; i < *N; i++) {
        if((*N) % i == 0) {
            int cd = *N / i;
            if (gcd(i,cd) == 1) {
                *sum = *sum + i;
            }
        }
    }
    if ((*sum) == (*N)) {
        printf("%d is a unitary perfect number.", *N);
    } else {
        printf("%d is not a unitary perfect number.", *N);
    }
    
}