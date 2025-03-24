#include <iostream>
#include <iomanip>
using namespace std;

class Order {
protected:
    double p, d, ad;
    int q;
public:
    Order(double p, int q, double d, double ad) : p(p), q(q), d(d), ad(ad) {}
};

class FinalOrder : public Order {
protected:
    double tc;
public:
    FinalOrder(double p, int q, double d, double ad) : Order(p, q, d, ad) {
        tc = (p * q) * (1 - d / 100);
    }
    double getTotalCost() { return tc; }
};

class DiscountedOrder : public FinalOrder {
public:
    DiscountedOrder(double p, int q, double d, double ad) : FinalOrder(p, q, d, ad) {}
    void printTotalCost() { cout << "Total Cost: " << fixed << setprecision(2) << tc << endl; }
    void printFinalCost() { cout << "Final Cost: " << fixed << setprecision(2) << tc * (1 - ad / 100) << endl; }
};

int main() {
    double p, d, ad;
    int q;
    cin >> p >> q >> d >> ad;
    DiscountedOrder order(p, q, d, ad);
    order.printTotalCost();
    order.printFinalCost();
}