#include <stdio.h>
#include <string.h>

void main() {
    char str1[100], str2[100];
    int i, flag = 0;

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (str1[i] != str2[i]) {
            flag = 1;
            break;
        }
    }

    if (flag == 0 && str1[i] == '\0' && str2[i] == '\0') {
        printf("Strings are equal\n");
    } else {
        printf("Strings are not equal\n");
    }
}