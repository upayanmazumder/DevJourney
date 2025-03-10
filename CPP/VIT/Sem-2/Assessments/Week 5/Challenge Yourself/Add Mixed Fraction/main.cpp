#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class Fraction {
private:
    int numerator, denominator;

public:
    Fraction(int num, int den) {
        numerator = num;
        denominator = den;
    }

    friend Fraction addMixedFraction(const Fraction& f1, const Fraction& f2);

    void print() {
        cout << numerator << "/" << denominator << endl;
    }
};

Fraction addMixedFraction(const Fraction& f1, const Fraction& f2) {
    int num1 = f1.numerator, den1 = f1.denominator;
    int num2 = f2.numerator, den2 = f2.denominator;
    int lcm = den1 * den2;
    int newNum1 = num1 * den2;
    int newNum2 = num2 * den1;
    int sumNumerator = newNum1 + newNum2;
    int sumDenominator = lcm;
    int divisor = gcd(sumNumerator, sumDenominator);
    sumNumerator /= divisor;
    sumDenominator /= divisor;
    return Fraction(sumNumerator, sumDenominator);
}

int main() {
    int num1, den1, num2, den2;
    cin >> num1 >> den1;
    cin >> num2 >> den2;
    Fraction f1(num1, den1);
    Fraction f2(num2, den2);
    Fraction result = addMixedFraction(f1, f2);
    result.print();
    return 0;
}