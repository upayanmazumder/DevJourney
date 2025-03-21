#include<stdio.h>

void main() {
    int x, *p1, **p2;
    x = 100;
    p1 = &x;
    p2 = &p1;
    printf("%d %u \n",x,&x);
    printf("%d %u \n",p1,&p1);
    printf("%d \n",*p1);
    printf("%d %u \n",p2,&p2);
    printf("%d \n", **p2);
}