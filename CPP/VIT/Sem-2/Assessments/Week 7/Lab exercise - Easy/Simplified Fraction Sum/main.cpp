#include <iostream>
#include <algorithm>

using namespace std;

class Fraction {
int numerator, denominator;
public:
Fraction(int num, int den) : numerator(num), denominator(den) {}
Fraction operator+(const Fraction& other) const {
    int num = numerator * other.denominator + other.numerator * denominator;
    int den = denominator * other.denominator;
    int gcdValue = __gcd(num, den);
    return Fraction(num / gcdValue, den / gcdValue);
}

void display() const {
    cout << numerator << "/" << denominator;
}

};
int main() {
int num1, den1, num2, den2;
cin >> num1 >> den1 >> num2 >> den2;
Fraction f1(num1, den1), f2(num2, den2);
Fraction result = f1 + f2;
result.display();

return 0;

}
