#include <stdio.h>

void greet() {
    printf("Hello, Upayan!\n");
}

int main() {
    void (*ptr)() = greet; // Function pointer
    ptr(); // Call function using pointer
    return 0;
}
