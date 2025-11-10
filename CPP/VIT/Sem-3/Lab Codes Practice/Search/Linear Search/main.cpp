#include <iostream>

using namespace std;

int linearSearch(const int arr[], int size, int target)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 6;
    int index = linearSearch(arr, size, target);
    if (index != -1)
    {
        cout << "Found at index " << index << '\n';
    }
    else
    {
        cout << "Not found\n";
    }
    return 0;
}
