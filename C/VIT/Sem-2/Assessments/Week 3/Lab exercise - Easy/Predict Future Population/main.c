#include <stdio.h>
#include <math.h>

void Growth(double *N, double *M, double *T, double *predictedPopulation) {
    *predictedPopulation = (*N)*exp((*M)*(*T));
}

int main() {
    double N, M, T, predictedPopulation;
    scanf("%lf\n", &N);
    scanf("%lf\n", &M);
    scanf("%lf\n", &T);
    Growth(&N, &M, &T, &predictedPopulation);
    printf("%.2lf\n", predictedPopulation);
}