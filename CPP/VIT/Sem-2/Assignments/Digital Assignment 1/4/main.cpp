#include <iostream>
using namespace std;

class MathSymbol {
public:
    virtual int doOperation(int, int) = 0;
};

class Plus : public MathSymbol {
public:
    int doOperation(int a, int b) {
        return a + b;
    }
};

class Minus : public MathSymbol {
public:
    int doOperation(int a, int b) {
        return a - b;
    }
};

int main() {
    int a, b;
    cout << "Enter 1st number: ";
    cin >> a ;
    cout << "Enter 2nd number: ";
    cin >> b;
    Plus p;
    Minus m;
    cout << "Sum: " << p.doOperation(a, b) << endl;
    cout << "Difference: " << m.doOperation(a, b) << endl;
    return 0;
}
