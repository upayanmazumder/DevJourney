#include <stdio.h>
#include <stdlib.h>

int main() {
    // 1. Static Memory Allocation (Compile-Time)
    int staticArray[3] = {1, 2, 3};  
    printf("Static Array: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", staticArray[i]);
    }
    printf("\n");

    // 2. Dynamic Memory Allocation using malloc()
    int *dynamicArray = (int *)malloc(3 * sizeof(int)); 
    if (dynamicArray == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Assign values
    for (int i = 0; i < 3; i++) {
        dynamicArray[i] = (i + 1) * 10;  // {10, 20, 30}
    }

    printf("Dynamic Array (malloc): ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");

    // 3. Resizing Memory using realloc()
    dynamicArray = (int *)realloc(dynamicArray, 5 * sizeof(int));  
    if (dynamicArray == NULL) {
        printf("Reallocation failed\n");
        return 1;
    }

    dynamicArray[3] = 40;
    dynamicArray[4] = 50;

    printf("Resized Array (realloc): ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");

    // 4. Using calloc() (allocates and initializes with 0)
    int *zeroArray = (int *)calloc(3, sizeof(int));  
    if (zeroArray == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Zero-initialized Array (calloc): ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", zeroArray[i]);  // Prints 0s
    }
    printf("\n");

    // Free allocated memory
    free(dynamicArray);
    free(zeroArray);

    return 0;
}