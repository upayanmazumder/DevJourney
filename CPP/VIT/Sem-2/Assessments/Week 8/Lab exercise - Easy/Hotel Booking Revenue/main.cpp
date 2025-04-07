#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

template <typename T>
T calculateTotal(vector<T>& arr) {
    T total = 0;
    for (T val : arr) {
        total += val;
    }
    return total;
}

int main() {
    int n;
    cin >> n;

    vector<double> bookings(n);
    for (int i = 0; i < n; ++i) {
        cin >> bookings[i];
    }

    double total = calculateTotal(bookings);

    cout << fixed << setprecision(2) << total << endl;

    return 0;
}