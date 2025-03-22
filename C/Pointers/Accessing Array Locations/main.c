#include <stdio.h>

int main() {
    int arr[3] = {1, 2, 3};
    int *ptr = arr; // Equivalent to int *ptr = &arr[0];

    for (int i = 0; i < 3; i++) {
        printf("%d ", *(ptr + i)); // Using pointer arithmetic
    }
    
    return 0;
}
