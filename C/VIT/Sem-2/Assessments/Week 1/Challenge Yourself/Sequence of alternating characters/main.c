#include<stdio.h>

int main() {
    char char1, char2;
    int N,i,j,c1=1;
    scanf("%c %c %d",&char1,&char2,&N);
    for(i=1;i<=N;i++) {
        if(c1 > 0) {
            for(j=1;j<=i;j++) {
                printf("%c",char1);
            }
        } else {
            for(j=1;j<=i;j++) {
                printf("%c",char2);
            }
        }
        c1 *= -1;
        printf(" ");
    }
}