#include<stdio.h>

int main() {
    int M,N,X,count=0,i,num,r;
    scanf("%d %d %d",&M,&N,&X);
    for(i=M;i<=N;i++) {
        num = i;
        while (num > 0) {
            r = num % 10;
            if (r > X) {
                count++;
            }
            num = (num-r)/10;
        }
    }
    printf("%d",count);
}