#include <stdio.h>

int main()
{
    int a[10], b[10], i, j, temp;
    bool all_same = true;
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < 10; i++)
    {
        if (all_same == false)
        {
            break;
        }
        for (j = 0; j < 10; j++)
        {
            if (all_same == false)
            {
                break;
            }
            if ((i != j) && (a[i] != a[j]))
            {
                all_same = false;
            }
        }
    }

    if (all_same)
    {
        printf("All elements are the same");
    }
    else
    {
        printf("Arranged elements are:");

        for (i = 0; i < 9; i++)
        {
            for (j = i + 1; j > 0; j--)
            {
                if (a[j] < a[j - 1])
                {
                    temp = a[j];
                    a[j] = a[j - 1];
                    a[j - 1] = temp;
                }
            }
        }

        for (i = 0; i < 10; i++)
        {
            printf(" %d", a[i]);
        }
    }
}