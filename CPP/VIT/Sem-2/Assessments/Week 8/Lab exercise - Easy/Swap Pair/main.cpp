#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Pair {
    T1 first;
    T2 second;

public:
    Pair(T1 a, T2 b) : first(a), second(b) {}

    void swap() {
        T1 temp = first;
        first = static_cast<T1>(second);
        second = static_cast<T2>(temp);
    }

    void display(const string& message) {
        cout << message << " First: " << first << " Second: " << second << endl;
    }
};

int main() {
    float f;
    double d;

    cin >> f >> d;

    Pair<float, double> p(f, d);
    p.display("Values before swap:");
    p.swap();
    p.display("Values after swap:");

    return 0;
}