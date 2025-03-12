#include <stdio.h>
union ComplexNumber {
    struct {
        double real, imag;
    };
};

int main() {
    union ComplexNumber num1, num2, sum;
    scanf("%lf %lf", &num1.real, &num1.imag);
    scanf("%lf %lf", &num2.real, &num2.imag);
    sum.real = num1.real + num2.real;
    sum.imag = num1.imag + num2.imag;
    printf("%.2lf + %.2lfi\n", sum.real, sum.imag);
}