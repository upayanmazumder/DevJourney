#include <stdio.h>

int main()
{
    int min = 1000, max = -1000, a[20], n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] < min)
        {
            min = a[i];
        }
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    printf("Maximum element is: %d\n", max);
    printf("Minimum element is: %d", min);
}