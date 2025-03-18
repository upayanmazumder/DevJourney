#include <stdio.h>

int main() {
    int n;
    printf("How many elements: ");
    scanf("%d", &n);
    int arr[n], i, *ptr = arr;
    
    for(i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", (ptr + i));
    }

    for(i = 0; i < n; i++) {
        printf("%d ", *(ptr + i));
    }
}