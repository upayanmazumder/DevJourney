#include <iostream>
using namespace std;

template <class T>
class Box {
    T value;
public:
    Box(T v) : value(v) {}
    void show() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Box<int> b1(100);
    Box<string> b2("Generic");

    b1.show();
    b2.show();
}
