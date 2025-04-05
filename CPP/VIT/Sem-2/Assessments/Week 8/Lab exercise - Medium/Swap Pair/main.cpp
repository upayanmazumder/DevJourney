#include <iostream>
using namespace std;

template <typename T1, typename T2>
class PairDerived {
    T1 first;
    T2 second;

public:
    void input(T1 a, T2 b) {
        first = a;
        second = b;
    }

    void display(const string& message) {
        cout << message << endl;
        cout << "First: " << first << endl;
        cout << "Second: " << second << endl;
    }

    void swapValues() {
        auto temp = first;
        first = static_cast<T1>(second);
        second = static_cast<T2>(temp);
    }
};

int main() {
    float f;
    double d;
    cin >> f >> d;

    PairDerived<float, double> pair;
    pair.input(f, d);

    pair.display("Values before swap:");
    pair.swapValues();
    pair.display("Values after swap:");

    return 0;
}