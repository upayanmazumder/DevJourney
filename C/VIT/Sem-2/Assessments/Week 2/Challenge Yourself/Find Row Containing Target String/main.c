#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d\n", &n);
    char arr[n][30];
    char str[100];
    int a = 0, b;

    for (int i = 0; i < n; i++)
        scanf("%s ", arr[i]);

    scanf("\n%s", str);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(str, arr[i]) == 0)
        {
            a = 1;
            b = i + 1;
            break;
        }
    }
    if (a == 1)
        printf("Found in row: %d", b);
    else
        printf("Not found");
}