#include <iostream>
#include <iomanip>

using namespace std;
    class Finder {
    public:
    int findMin(int a, int b, int c) {
    return min(a, min(b, c));
    }
    double findMin(double x, double y, double z) {
        return min(x, min(y, z));
    }
};

int main() {
    int a, b, c;
    double x, y, z;
    cin >> a >> b >> c >> x >> y >> z;
    Finder finder;
    cout << "Minimum integer: " << finder.findMin(a, b, c) << " ";
    cout << "Minimum double-point value: " << fixed << setprecision(2) << finder.findMin(x, y, z);

    return 0;
}
