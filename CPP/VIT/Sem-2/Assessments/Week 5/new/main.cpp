#include <iostream>
#include <iomanip>
using namespace std;

class Distance {
public:
    int s, t;
    Distance(int a, int b) : s(a), t(b) {}
    friend double calcDistance(Distance d);
};

double calcDistance(Distance d) {
    return d.s * d.t;
}

int main() {
    int s, t;
    cin >> s >> t;
    Distance d(s, t);
    cout << fixed << setprecision(2) << calcDistance(d) << "\n";
}