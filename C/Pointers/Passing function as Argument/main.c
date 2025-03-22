#include <stdio.h>

void printMessage() {
    printf("Welcome to Pointers!\n");
}

void execute(void (*func)()) {
    func(); // Call function passed as argument
}

int main() {
    execute(printMessage);
    return 0;
}
