#include <stdio.h>

int main() {
    int N, i, m[10], *ptr, sum;
    scanf("%d", &N);
    ptr = m;
    sum = 0;
    for(i = 0; i < N; i++) {
        scanf("%d",(ptr + i));
    }
    for(i = 0; i < N; i++) {
        sum += *(ptr + i);
    }
    printf("%d",sum);
}