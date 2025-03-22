#include <stdio.h>
#include <stdlib.h>

union Data {
    int i;
    float f;
    char str[20];
};

int main() {
    union Data data;
    data.i = 10;
    printf("Integer: %d\n", data.i);

    data.f = 220.5; // Overwrites 'i'
    printf("Float: %.1f\n", data.f);

    return 0;
}
