#include<stdio.h>

int main() {
    float cp,sp,net;
    scanf("%f",&cp);
    scanf("%f",&sp);
    if (cp > sp) {
        net = cp-sp;
        printf("Loss = %7.2f",net);
    } else if (cp < sp) {
        net = sp-cp;
        printf("Profit = %7.2f",net);
    } else {
        printf("No profit or no loss");
    }
}