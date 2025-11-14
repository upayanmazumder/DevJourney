#include <iostream>
using namespace std;

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
    cin >> n;

    int A[1000]; // static array for simplicity

    for (int i = 0; i < n; i++)
        cin >> A[i];

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
    cin >> x;

    int pos = binarySearch(A, n, x);

    if (pos == -1)
        cout << "Element not found";
    else
        cout << "Element found at " << pos + 1 << " position";

    return 0;
}
