#include<stdio.h>

int main() {
    int age1,age2,yC,yF,diff,i,a1,a2,found=0;
    scanf("%d %d %d %d",&age1,&age2,&yC,&yF);
    diff = yF - yC;
    for(i=0;i<=diff;i++) {
        a1 = age1 + i;
        a2 = age2 + i;
        if ((a1 == 2*a2) || (a2 == 2*a1)) {
            printf("%d",i);
            found += 1;
        }
    }
    if (found == 0) {
        printf("No such year found upto %d",yF);
    }
    
}