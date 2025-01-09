#include <stdio.h>

void incrementCounter() {
    static int counter = 0;
    counter++;
    printf("Counter: %d\n", counter);
}

int main() {
    incrementCounter();
    incrementCounter();
    incrementCounter();
    return 0;
}