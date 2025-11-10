#include <iostream>

using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int size)
{
    for (int i = size / 2 - 1; i >= 0; --i)
    {
        heapify(arr, size, i);
    }
    for (int i = size - 1; i > 0; --i)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {4, 10, 3, 5, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, size);
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    return 0;
}
