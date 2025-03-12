#include <stdio.h>
#define NUM_CITIES 3
#define MAX_NAME_LENGTH 50

int main() {
    char cityNames[NUM_CITIES][MAX_NAME_LENGTH];
    int populations[NUM_CITIES];
    int *popPtr = populations;
    int total_population = 0;
    double average_population;
    for (int i = 0; i < NUM_CITIES; i++) {
        scanf("%s %d", *(cityNames +i), (popPtr + i));
    }
    for(int i = 0; i < NUM_CITIES; i++) {
        total_population += *(popPtr + i);
    }
    average_population = (double) total_population / NUM_CITIES;
    printf("%d\n", total_population);
    printf("%.2f\n", average_population);
}