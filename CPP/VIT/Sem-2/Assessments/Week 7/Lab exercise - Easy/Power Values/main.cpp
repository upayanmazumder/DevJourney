#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Expression {
public:
    virtual double evaluate() = 0;
    virtual ~Expression() {}
};

class PowerAB : public Expression {
    double a, b;
public:
    PowerAB(double a, double b) : a(a), b(b) {}
    double evaluate() override {
        return pow(a, b);
    }
};

class PowerBA : public Expression {
    double a, b;
public:
    PowerBA(double a, double b) : a(a), b(b) {}
    double evaluate() override {
        return pow(b, a);
    }
};

int main() {
    double a, b;
    cin >> a >> b;

    PowerAB exp1(a, b);
    PowerBA exp2(a, b);

    cout << fixed << setprecision(2);
    cout << exp1.evaluate() << "\n" << exp2.evaluate();

    return 0;
}