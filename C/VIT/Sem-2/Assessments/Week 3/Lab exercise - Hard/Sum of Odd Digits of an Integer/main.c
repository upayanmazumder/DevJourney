#include<stdio.h>

int main() {
    int n, sum = 0, d;
    scanf("%d", &n);
    int *ptr = &n;
    while(*ptr) {
        d = *ptr % 10;
        if (d % 2 != 0) {
            sum += d;
        }
        *ptr /= 10;
    }
    printf("%d",sum);
}