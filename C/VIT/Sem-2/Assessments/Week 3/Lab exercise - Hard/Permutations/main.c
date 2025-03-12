#include <stdio.h>

long long factorial(int *num) {
    long long fact = 1;
    for(int i = 1; i <= *num; i++) {
        fact *= i;
    }
    return fact;
}

long long calculatePermutations(int *n, int *r) {
    int n_r =* n - *r;
    return factorial(n) / factorial(&n_r);
}

int main() {
    int n,r;
    scanf("%d %d", &n, &r);
    if (r > n) {
        return 1;
    }
    long long result = calculatePermutations(&n, &r);
    printf("%lld\n", result);
}