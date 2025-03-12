#include<stdio.h>

int main() {
    int l,b,a, *L = &l,*B = &b,*A = &a;
    scanf("%d %d",L,B);
    *A = *L * *B;
    printf("%d",*A);
}