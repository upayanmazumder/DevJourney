#include<stdio.h>

void foobar(int a, int b, int *q, int *r) {
    *q = a / b;
    *r = a % b;
}

int main() {
    int a,b,r,q;
    scanf("%d %d",&a,&b);
    foobar(a,b,&q,&r);
    printf("%d %d", q, r);
}
