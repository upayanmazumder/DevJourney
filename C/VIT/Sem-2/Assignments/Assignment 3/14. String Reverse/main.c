#include <stdio.h>
#include <string.h>

void main() {
    char str[100], rev[100];
    int i, j;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    for (i = 0; str[i] != '\0'; i++)
        ;

    for (j = 0; i >= 0; i--, j++) {
        rev[j] = str[i - 1];
    }

    rev[j] = '\0';

    printf("Reversed string: %s\n", rev);
}