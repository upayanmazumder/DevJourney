#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(2 * sizeof(int));
    ptr[0] = 10;
    ptr[1] = 20;

    // Resize memory to hold 4 integers
    ptr = (int *)realloc(ptr, 4 * sizeof(int));
    
    ptr[2] = 30;
    ptr[3] = 40;

    for (int i = 0; i < 4; i++) {
        printf("%d ", ptr[i]);
    }

    free(ptr);
    return 0;
}
