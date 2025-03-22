//  Write a program that allocates memory dynamically for a string, 
// takes user input, and prints the string.

#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str = (char *)malloc(50 * sizeof(char));
    scanf("%s", str);
    printf("%s", str);
    free(str);
    printf("\nFreed memory");
}
