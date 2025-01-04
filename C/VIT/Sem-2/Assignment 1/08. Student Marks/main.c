#include<stdio.h>

int main() {
    int i,m[5],total=0,num,p;
    for(i=0;i<5;i++) {
        printf("Enter marks in subject %d: ",i+1);
        scanf("%d",&num);
        m[i] = num;
        total += num;
    }
    p = total / 5;
    printf("Total marks = %d\nPercentage = %d\n",total,p);
}