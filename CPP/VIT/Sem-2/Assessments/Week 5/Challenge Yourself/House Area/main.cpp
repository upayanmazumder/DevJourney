#include <iostream>
#include <iomanip>
using namespace std;

class House {
public:
    double l, w, h;
    House(double a, double b, double c) : l(a), w(b), h(c) {}
    double tsa() { return 2 * ((w * h) + (h * l) + (h * l) + (w * h)); }
};

int main() {
    double l, w, h;
    cin >> l >> w >> h;
    cout << fixed << setprecision(2) << House(l, w, h).tsa() << " square units." << endl;
}