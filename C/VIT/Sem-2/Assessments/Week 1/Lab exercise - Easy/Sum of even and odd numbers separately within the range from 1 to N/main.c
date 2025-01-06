#include<stdio.h>

int main() {
    int N,sumE=0,sumO=0,i;
    scanf("%d",&N);
    for(i=1;i<=N;i++) {
        if (i % 2 == 0) {
            sumE += i;
        } else {
            sumO += i;
        }
    }
    printf("Sum of even numbers: %d\n",sumE);
    printf("Sum of odd numbers: %d\n",sumO);
}