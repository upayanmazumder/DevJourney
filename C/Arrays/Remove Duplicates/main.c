#include<stdio.h>

int main() {
    int i,j,n,a[100],dup[100],dupN=0;

    printf("How many numbers: ");
    scanf("%d",&n);

    for(i=0;i<n;i++) {
        printf("Enter %dth element: ",i+1);
        scanf("%d",&a[i]);
    }

    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            if (i != j) {
                if (a[i] == a[j]) {
                    dup[dupN] = j;
                    dupN++;
                }
            }
        }
    }
    
    for(i=0;i<dupN;i++) {
        printf("%d",dup[i]);
    }
}