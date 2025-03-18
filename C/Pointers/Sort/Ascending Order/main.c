#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    printf("How many elements: ");
    scanf("%d", &n);
    int arr[n], *ptr = arr, i, j, temp;
    bool clean = false;

    for (i = 0; i < n; i++) {
        printf("Enter %dth element: ", i + 1);
        scanf("%d", (ptr + i));
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (*(ptr + j) > *(ptr + j + 1)) {
                temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }

    for(i = 0; i < n; i++) {
        printf("%d ", *(ptr + i));
    }

}