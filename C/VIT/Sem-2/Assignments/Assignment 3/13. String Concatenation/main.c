#include <stdio.h>
#include <string.h>

void main() {
    char str1[200], str2[100];
    int i, j;

    printf("Enter original string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';
    printf("Enter suffix string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    for (i = 0; str1[i] != '\0'; i++)
        ;

    for (j = 0; str2[j] != '\0'; j++, i++) {
        str1[i] = str2[j];
    }
    str1[i] = '\0';

    printf("Concatenated string: %s\n", str1);
}