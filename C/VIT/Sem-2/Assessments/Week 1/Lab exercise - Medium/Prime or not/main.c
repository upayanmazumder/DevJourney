#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main() {
    int i,prime=1,N,x;
    scanf("%d",&N);
    x = abs(N);
    if (x == 0) {
        printf("0 is not a prime number.");
    } else if(N == 2) {
        printf("%d is a prime number.",N);
    } else if(N == -2) {
        printf("%d is not a prime number.",N);
    } else {
        for(i = 2;i < x;i++) {
            if (x % i == 0) {
                prime = 0;
                break;
            }
        }
        if (prime == 1) {
            printf("%d is a prime number.",N);
        } else {
            printf("%d is not a prime number.",N);
        }
    }
}