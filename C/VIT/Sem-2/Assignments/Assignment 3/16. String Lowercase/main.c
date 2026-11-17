#include <stdio.h>
#include <string.h>

void main() {
    char str[100], low[100];
    int i;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            low[i] = str[i] + 32;
        } else {
            low[i] = str[i];
        }
    }
    low[i] = '\0';

    printf("Lowercase string: %s\n", low);
}