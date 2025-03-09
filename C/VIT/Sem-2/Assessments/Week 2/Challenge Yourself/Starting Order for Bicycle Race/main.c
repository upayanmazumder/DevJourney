#include <stdio.h>

void rotateArray(int arr[], int n, int m)
{
    int arr1[n];
    for (int i = 0; i < n; i++)
    {
        arr1[(i + m) % n] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]);
    }
}

int main()
{
    int N, M;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &M);
    rotateArray(arr, N, M);
}