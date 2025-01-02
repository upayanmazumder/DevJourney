#include<stdio.h>

int main() {
    int i,x,a[100],p,n;

    printf("How many numbers: ");
    scanf("%d",&x);

    for(i=0;i<x;i++) {
        printf("Enter %dth number: ",i+1);
        scanf("%d",&a[i]);
    }
    printf("The array is: ");
    for(i=0;i<x;i++) {
        printf("%d ",a[i]);
    }
    printf("\nEnter index of element to be removed: ");
    scanf("%d",&p);
    for(i=p;i<x;i++) {
        a[i] = a[i+1];
    }
    printf("The updated array is: ");
    x--;
    for(i=0;i<x;i++) {
        printf("%d ",a[i]);
    }
}