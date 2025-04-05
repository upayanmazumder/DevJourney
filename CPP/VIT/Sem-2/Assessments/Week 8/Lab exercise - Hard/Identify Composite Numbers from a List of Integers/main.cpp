#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0) return false;
    return true;
}

int main() {
    int n;
    cin >> n;

    if (n < 1 || n > 15) {
        cout << -1;
        return 0;
    }

    vector<int> input(n), composites;

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    remove_copy_if(input.begin(), input.end(), back_inserter(composites), [](int x) {
        return isPrime(x) || x <= 1;
    });

    if (composites.empty()) {
        cout << -1;
    } else {
        cout << "Composite numbers:";
        for (int x : composites) {
            cout << " " << x;
        }
    }

    return 0;
}