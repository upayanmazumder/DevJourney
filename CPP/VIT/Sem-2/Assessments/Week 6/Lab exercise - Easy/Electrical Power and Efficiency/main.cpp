#include <iostream>
#include <iomanip>
using namespace std;

class P {
protected:
    double v, c, power;
public:
    P(double v, double c) : v(v), c(c) { power = v * c; }
    double getPower() { return power; }
};

class PE : public P {
    double e;
public:
    PE(double v, double c, double e) : P(v, c), e(e) {}
    void display() {
        cout << fixed << setprecision(1);
        cout << "Power: " << power << "W\n";
        cout << "Useful Output Power: " << power * e << "W\n";
        cout << "Wasted Power: " << power * (1 - e) << "W\n";
    }
};

int main() {
    double v, c, e;
    cin >> v >> c >> e;
    PE obj(v, c, e);
    obj.display();
}