#include <iostream>
#include <iomanip>
using namespace std;

class Principal {
protected:
    double price;
public:
    Principal(double p) : price(p) {}
};

class InterestRate {
protected:
    double rate;
public:
    InterestRate(double r) : rate(r) {}
};

class Loan : public Principal, public InterestRate {
    int years;
public:
    Loan(double p, double r, int y) : Principal(p), InterestRate(r), years(y) {}

    void calculateTotalInterest() {
        double totalInterest = price * rate * years;
        cout << fixed << setprecision(2);
        cout << "Total interest paid: Rs." << totalInterest << endl;
    }
};

int main() {
    double price, rate;
    int years;

    cin >> price >> rate >> years;

    Loan loan(price, rate, years);
    loan.calculateTotalInterest();

    return 0;
}