#include <stdio.h>
#include <stdlib.h>

void findMaxMin(int *arr, int n, int *max, int *min) {
    *max = *arr;
    *min = *arr;
    for (int i = 1; i < n ; i ++) {
        if(*(arr + i) > *max) {
            *max = *(arr + i);
        }
        if(*(arr+i) < *min) {
            *min = *(arr + i);
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int *temperatures = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", (temperatures + i));
    }
    int maxTemp, minTemp;
    findMaxMin(temperatures, n, &maxTemp, &minTemp);
    printf("Highest temperatures: %d\n", maxTemp);
    printf("Lowest temperatures : %d\n", minTemp);
    free(temperatures);
}