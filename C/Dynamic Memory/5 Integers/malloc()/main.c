// Write a C program that uses malloc() to allocate memory for 5 integers, 
// takes input from the user, and prints the values.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, *arr;
    arr = (int *)malloc(5 * sizeof(int));

    for (i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    printf("\nFreed memory!");
}