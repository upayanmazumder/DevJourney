#include <iostream>
#include <iomanip>
using namespace std;

class CotRCal {
private:
    double weight, rate, totalCost;

public:
    CotRCal() : weight(0.0), rate(0.0), totalCost(0.0) {}

    CotRCal(double w, double r) {
        weight = w;
        rate = r;
        totalCost = weight * rate;
    }

    void display() {
        cout << "Weight: " << fixed << setprecision(1) << weight << " kg\n";
        cout << "Rate: Rs. " << fixed << setprecision(1) << rate << " per kg\n";
        cout << "Total Cost: Rs. " << fixed << setprecision(2) << totalCost << endl;
    }
};

int main() {
    double W, R;
    cin >> W >> R;

    CotRCal obj(W, R);
    obj.display();

    return 0;
}