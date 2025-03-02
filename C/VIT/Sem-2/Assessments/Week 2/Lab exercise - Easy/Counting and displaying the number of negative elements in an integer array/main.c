#include <stdio.h>

int main()
{
    int n, a[10], i, c = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] < 0)
        {
            c++;
        }
    }
    if (c > 0)
    {
        printf("Total negative elements in array = %d", c);
    }
    else
    {
        printf("No negative elements in the array");
    }
}