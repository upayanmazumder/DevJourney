#include<stdio.h>

int main() {
    int type,speed,max;
    scanf("%d",&type);
    scanf("%d",&speed);
    switch(type) {
        case 1:
            max = 25;
            break;
        case 2:
            max = 35;
            break;
        case 3:
            max = 55;
            break;
    }
    
    if (speed < max) {
        printf("Below");
    } else if (speed > max) {
        printf("Above");
    } else {
        printf("Normal");
    }
}