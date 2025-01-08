#include<stdio.h>

void main() {
    char str[100], up[100];
    int i, j;

    printf("Enter a string: ");
    gets(str);

    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            up[i] = str[i] - 32;
        } else {
            up[i] = str[i];
        }
    }
    up[i] = '\0';

    printf("Uppercase string: %s\n", up);
}