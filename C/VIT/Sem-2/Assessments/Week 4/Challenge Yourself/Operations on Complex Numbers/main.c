#include <stdio.h>
#include <math.h>

typedef struct {
    float real, imag;
} Complex;

Complex addComplex(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

Complex subtractComplex(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

Complex multiplyComplex(Complex a, Complex b) {
    Complex result;
    result.real = (a.real * b.real) - (a.imag * b.imag);
    result.imag = (a.real * b.imag) + (a.imag * b.real);
    return result;
}

float modulusComplex(Complex a) {
    return sqrt((a.real * a.real) + (a.imag * a.imag));
}

int main() {
    Complex nums[2];
    for (int i = 0; i < 2; i++) {
        scanf("%f %f", &nums[i].real, &nums[i].imag);
    }
    Complex sum = addComplex(nums[0], nums[1]);
    Complex diff = subtractComplex(nums[0], nums[1]);
    Complex prod = multiplyComplex(nums[0], nums[1]);
    float mod1 = modulusComplex(nums[0]);
    float mod2 = modulusComplex(nums[1]);
    printf("%.2f + %.2fi\n", sum.real, sum.imag);
    if (diff.imag < 0) {
        printf("%.2f + -%.2fi\n", diff.real, fabs(diff.imag));
    } else {
        printf("%.2f + %.2fi\n", diff.real, diff.imag);
    }
    printf("%.2f + %.2fi\n", prod.real, prod.imag);
    printf("%.2f\n", mod1);
    printf("%.2f\n", mod2);
    
}