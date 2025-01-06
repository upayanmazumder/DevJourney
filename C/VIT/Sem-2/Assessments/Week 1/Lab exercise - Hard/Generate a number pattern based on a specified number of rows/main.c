#include<stdio.h>

int main() {
    int i,j,N;
    scanf("%d",&N);
    for(i=0;i<N;i++) {

        for(j=N-i-1;j>0;j--) {
            printf("  ");
        }

        for(j=i;j<2*i+1;j++) {
            printf("%d ",j+1);
        }

        for(j=2*i;j>i;j--) {
            printf("%d ",j);
        }
        printf("\n");
    }
}