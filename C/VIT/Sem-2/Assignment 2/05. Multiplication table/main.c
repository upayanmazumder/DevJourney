#include<stdio.h>

int main() {
    int i,m,n;

    printf("Number to generate table of : ");
    scanf("%d",&m);

    printf("How many multiples: ");
    scanf("%d",&n);

    printf("Multiplication table of %d upto %dth multiple: ",m,n);
    
    for(i = 1;i <= n;i++) {
        printf("\n%d x %d = %d",m,i,m*i);
    }
}