#include <stdio.h>
#include <stdlib.h>

int binarySearch(int A[], int n, int x)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (A[mid] == x)
            return mid; // return index
        else if (A[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // not found
}

int main()
{
    int n;
    if (scanf("%d", &n) != 1)
        return 0;

    int A[1000]; // static array for simplicity

    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    // sort array (binary search needs sorted data)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[i])
            {
                int temp = A[j];
                A[j] = A[i];
                A[i] = temp;
            }
        }
    }

    int x;
    scanf("%d", &x);

    int pos = binarySearch(A, n, x);

    if (pos == -1)
        printf("Element not found");
    else
        printf("Element found at %d position", pos + 1);

    return 0;
}
