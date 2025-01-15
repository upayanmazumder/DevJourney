#include<stdio.h>
#include<string.h>

int main() {
    char D[20];
    char R;
    
    scanf("%s",D);
    
    scanf(" %c",&R);
    
    double S,res=1.23;
    
    scanf("%lf",&S);
    
    if (strcmp(D, "Sales") == 0) {
        if (R == 'A') {
            res = S / 5;
        } else if (R == 'B') {
            res =  0.15 * S;
        } else if (R == 'C') {
            res =  0.1 * S;
        }
    } else if (strcmp(D, "Engineering") == 0) {
        if (R == 'A') {
            res = S / 4;
        } else if (R == 'B') {
            res =  S / 5;
        } else if (R == 'C') {
            res =  0.15 * S;
        }
    } else if (strcmp(D, "HR") == 0) {
        if (R == 'A') {
            res = S * 0.15;
        } else if (R == 'B') {
            res =  S * 0.10;
        } else if (R == 'C') {
            res =  S * 0.05;
        }
    }
    
    printf("Annual Bonus: $%.2lf",res);
}