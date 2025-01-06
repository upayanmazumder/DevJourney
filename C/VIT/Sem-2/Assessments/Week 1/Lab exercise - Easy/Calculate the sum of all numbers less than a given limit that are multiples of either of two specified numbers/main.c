#include<stdio.h>

int main() {
    int N,M,P,i,sum=0;
    scanf("%d",&N);
    scanf("%d",&M);
    scanf("%d",&P);
    for(i=N-1;i>0;i--) {
        if ((i%M==0) || (i%P==0)) {
            sum += i;
        }
    }
    printf("%d",sum);
}