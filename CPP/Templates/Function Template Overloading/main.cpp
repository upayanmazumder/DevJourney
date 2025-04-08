#include <iostream>
using namespace std;

template<class X>
void fun(X a, X b) {
    cout << "Same type: " << a + b << endl;
}

template<class X, class Y>
void fun(X a, Y b) {
    cout << "Different types: " << a + b << endl;
}

int main() {
    fun(2, 3);
    fun(2.5, 3.5);
    fun(2, 3.5);
    return 0;
}
