#include<stdio.h>

int main() {
    int i,j,x,y,a[100][100];
    printf("Enter dimensions [rows] [columns]: ");
    scanf("%d %d",&x,&y);
    for(i=0;i<x;i++) {
        for(j=0;j<y;j++) {
            printf("Enter element [%d][%d]: ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<x;i++) {
        for(j=0;j<y;j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}