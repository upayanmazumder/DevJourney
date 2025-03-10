#include <iostream>
using namespace std;

class Operation {
private:
    int num1, num2;

public:
    void get();  
    void sum();
    void difference();
    void product();
    void division();
    void modulus();
};

inline void Operation::get() {
    cin >> num1 >> num2;
}

inline void Operation::sum() {
    cout << "Addition of two numbers: " << (num1 + num2) << endl;
}

inline void Operation::difference() {
    cout << "Difference of two numbers: " << (num1 - num2) << endl;
}

inline void Operation::product() {
    cout << "Product of two numbers: " << (num1 * num2) << endl;
}

inline void Operation::division() {
    cout << "Division of two numbers: " << (num1 / num2) << endl;
}

inline void Operation::modulus() {
    cout << "Modulus of two numbers: " << (num1 % num2) << endl;
}

int main() {
    Operation op;
    op.get();
    op.sum();
    op.difference();
    op.product();
    op.division();
    op.modulus();
    return 0;
}