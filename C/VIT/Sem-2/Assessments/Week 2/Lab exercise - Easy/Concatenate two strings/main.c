#include <stdio.h>

int main()
{
    int i = 0, x;
    char a[25], b[25], res[50];
    fgets(a, sizeof(a), stdin);
    fgets(b, sizeof(b), stdin);

    while (a[i] != '\0')
    {
        res[i] = a[i];
        i++;
    }
    x = i;
    i = 0;

    while (b[i] != '\0')
    {
        res[i + x] = b[i];
        i++;
    }

    i = 0;
    while (res[i] != '\0')
    {
        if (res[i] != '\n')
            printf("%c", res[i]);
        i++;
    }
}