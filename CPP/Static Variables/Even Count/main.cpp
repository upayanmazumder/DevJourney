#include <iostream>
using namespace std;

int count() {
    static int c = 0;
    c++;
    return c;
}

int main() {
    int i, n;
    cout << "How many numbers to check, starting from 0: ";
    cin >> n;
    int counter = 0;

    for (i = 0; i <= n; i++) {
        if (i % 2 == 0)
            counter = count();
    }

    cout << "Count of even numbers: " << counter << endl;
    return 0;
}
