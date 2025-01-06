#include<stdio.h>

int main() {
    int C,p=0;
    float X;
    scanf("%d",&C);
    scanf("%f",&X);
    switch(C) {
        case 1:
            if (X < 50) {
                p = 1;
            }
            break;
        case 2:
            if (X > 80) {
                p = 1;
            }
            break;
        case 3:
            if (X > 80) {
                p = 1;
            }
            break;
        default:
            printf("Invalid");
            break;
    }
    if ((C >= 1) && (C <=3)) {
        printf("Priority: ");
        if (p == 1) {
            printf("High");
        } else {
            printf("Low");
        }
    }
}