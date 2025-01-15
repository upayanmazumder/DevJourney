#include<stdio.h>

int main() {
    int p=1, N, c=0, r;
    scanf("%d", &N);
    
    while (N > 0) {
        r = N % 10;
        p *= r;
        N /= 10;
        c++;
    }
    
    if (p > 9 && p % 2 == 0) {
        printf("%d", c);
    } else {
        printf("%d", c);
    }
    
    return 0;
}