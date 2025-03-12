#include<stdio.h>

int main() {
    int age, n;
    scanf("%d %d", &age, &n);
    float cB = 150.0, cV = 300.0, cT, d = 0.0;
    float *price;
    price = (age < 18) ? &cB : &cV;
    d = (age < 18) ? 10.0 : 5.0;
    cT = (*price - (*price * d / 100)) * n;
    printf("Rs.%.2f", cT);
}