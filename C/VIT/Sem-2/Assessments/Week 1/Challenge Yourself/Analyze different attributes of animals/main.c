#include<stdio.h>
#include<ctype.h>

int main() {
    char c;
    float x,y,res;
    scanf("%c",&c);
    scanf("%f",&x);
    c = tolower(c);
    switch(c) {
        case 'd':
            res = x * 343;
            printf("Distance: %.2f m",res);
            break;
        case 'b':
            res = x * 5;
            printf("Weight: %.2f lb",res);
            break;
        case 'f':
            scanf("%f",&y);
            res = x * y;
            printf("Altitude: %.2f m",res);
            break;
        default:
            printf("Invalid");
    }
}