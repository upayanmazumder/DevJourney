#include<stdio.h>
#include<math.h>

double calculateHypotenuse(double *a, double *b) {
    return sqrt((*a) * (*a) + (*b) * (*b));
}

int main() {
    double side1, side2;
    scanf("%lf %lf", &side1, &side2);
    double hypotenuse = calculateHypotenuse(&side1, &side2);
    printf("%.2lf\n", hypotenuse);
}