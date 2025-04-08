#include <iostream>
using namespace std;

template <class T>
T maximum(T a, T b, T c) {
    T max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    return max;
}

int main() {
    cout << maximum(3, 7, 5) << endl;
    cout << maximum(3.5, 7.2, 5.8) << endl;
    return 0;
}
