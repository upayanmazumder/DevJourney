#include <stdio.h>
#include "../../utils.h"

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {5, 1, 4, 2, 8};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original: ");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Sorted:   ");
    printArray(arr, n);

    return 0;
}
