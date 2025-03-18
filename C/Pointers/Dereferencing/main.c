#include <stdio.h>

int main() {
    int myAge = 43;
    int *ptr = &myAge;

    printf("%p\n", ptr);

    printf("%d\n", *ptr);
}