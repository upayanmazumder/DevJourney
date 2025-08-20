#include <stdio.h>
#include "utils.h"

// Binary Search
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 40;

    int idx = binarySearch(arr, n, key);
    if (idx != -1)
        printf("Element %d found at index %d\n", key, idx);
    else
        printf("Element %d not found\n", key);

    return 0;
}
