#include<stdio.h>

int main() {
    int i,j,x,y,a[100][100],target,found=0;
    printf("Enter dimensions [rows] [columns]: ");
    scanf("%d %d",&x,&y);
    for(i=0;i<x;i++) {
        for(j=0;j<y;j++) {
            printf("Enter element [%d][%d]: ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter target element: ");
    scanf("%d",&target);
    for(i=0;i<x;i++) {
        for(j=0;j<y;j++) {
            if(a[i][j]==target) {
                printf("Element found at [%d][%d]\n",i+1,j+1);
                found = 1;
            }
        }
    }
    if (found == 0) {
        printf("The element is not present");
    }
}