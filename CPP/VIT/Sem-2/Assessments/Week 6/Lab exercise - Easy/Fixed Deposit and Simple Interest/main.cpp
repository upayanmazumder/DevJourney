#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Investment {
protected:
    double p, r, t;
public:
    Investment(double p, double r, double t) : p(p), r(r), t(t) {}
};

class FixedDeposit : public Investment {
protected:
    double m;
public:
    FixedDeposit(double p, double r, double t) : Investment(p, r, t) {
        m = p * pow(1 + (r / 100), t);
    }
    double getMaturity() { return m; }
};

class SimpleInterest : public FixedDeposit {
public:
    SimpleInterest(double p, double r, double t) : FixedDeposit(p, r, t) {}
    void printFD() { cout << "Maturity Amount: " << fixed << setprecision(2) << m << endl; }
    void calculateSimpleInterest() { cout << "Simple Interest: " << fixed << setprecision(2) << (p * t * r) / 100 << endl; }
};

int main() {
    double p, r, t;
    cin >> p >> r >> t;
    SimpleInterest si(p, r, t);
    si.printFD();
    si.calculateSimpleInterest();
}