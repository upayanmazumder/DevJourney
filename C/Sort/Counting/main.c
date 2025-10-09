#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n)
{
    int i;
    int max = arr[0], min = arr[0];

    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    int range = max - min + 1;
    int *count = (int *)calloc(range, sizeof(int));
    int output[n];

    for (i = 0; i < n; i++)
        count[arr[i] - min]++;

    for (i = 1; i < range; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];

    free(count);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {4, -2, -2, 8, 3, -1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    countingSort(arr, n);

    printf("Sorted array:   ");
    printArray(arr, n);

    return 0;
}
