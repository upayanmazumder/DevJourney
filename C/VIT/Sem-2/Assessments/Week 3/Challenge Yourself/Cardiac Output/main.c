#include <stdio.h>

void calculateCardiacOutput(double *heartRate, double *strokeVolume, double *cardiacOutput ) {
    *cardiacOutput = (*heartRate * *strokeVolume) / 1000.0;
}

int main() {
    double heartRate, strokeVolume, cardiacOutput;
    scanf("%lf %lf", &heartRate, &strokeVolume);
    calculateCardiacOutput(&heartRate, &strokeVolume, &cardiacOutput);
    printf("%.2lf liters per minute\n", cardiacOutput);
}