#include <stdio.h>
#include "utils.h"

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original: ");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sorted:   ");
    printArray(arr, n);

    return 0;
}
