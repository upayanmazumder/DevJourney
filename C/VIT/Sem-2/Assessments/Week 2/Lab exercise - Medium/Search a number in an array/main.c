#include <stdio.h>

int main()
{
    int n, a[10], x, i;
    bool found = false;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    scanf("%d", &x);

    for (i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            found = true;
        }
    }

    printf("The number %d is %spresent in the array", x, (found ? "" : "not "));
}