#include <iostream>
using namespace std;

template<class X>
void fun(X a, X b) {
    cout << "Sum: " << a + b << endl;
}

template<class X, class Y>
void fun(X a, Y b) {
    cout << "Mixed Sum: " << a + b << endl;
}

int main() {
    fun(2, 3);
    fun(2.5, 3.5);
    fun(2, 3.5);
    return 0;
}
