#include <stdio.h>

int main(void)
{
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 6;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        printf("Found at index %d\n", index);
    }
    else
    {
        printf("Not found\n");
    }
    return 0;
}
