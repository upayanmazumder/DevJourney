#include <stdio.h>

int main() {
    int a[20], n, i, *ptr = a;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", (ptr + i));
    }
    
    printf("Array before swap: ");
    for(i = 0; i < n; i++) {
        printf("%d ", *(ptr + i));
    }
    
    if (n > 1) {
        int temp = *ptr;
        *ptr = *(ptr + n - 1);
        *(ptr + n - 1) = temp;
    }
    printf("\nArray after swap: ");
    for(i = 0; i < n; i++) {
        printf("%d ", *(ptr + i));
    }
}