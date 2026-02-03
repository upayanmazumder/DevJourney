#include <iostream>
using namespace std;

bool subsetSum(int arr[], int n, int sum) {
    if (sum == 0)
        return true;
    if (n == 0 || sum < 0)
        return false;

    return subsetSum(arr, n - 1, sum) ||
           subsetSum(arr, n - 1, sum - arr[n - 1]);
}

int main() {
    int n, sum;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter target sum: ";
    cin >> sum;

    if (subsetSum(arr, n, sum))
        cout << "Subset with given sum exists";
    else
        cout << "Subset with given sum does NOT exist";

    return 0;
}
