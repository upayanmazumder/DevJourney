#include<stdio.h>

int main() {
    float m,M,X;
    int N;
    scanf("%d",&N);
    scanf("%f",&M);
    if (N >= 1 && N <=3){
        switch(N) {
            case 1:
                m = 1.5;
                break;
            case 2:
                m = 2;
                break;
            case 3:
                m=1.8;
                break;
        }
        X = M * m;
        printf("Intensity : %.2f",X);
    } else {
        printf("Invalid");
    }
}