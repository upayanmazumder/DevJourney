#include <iostream>
using namespace std;

class operationsBase {
public:
    virtual void addition() = 0;
    virtual void subtraction() = 0;
    virtual void multiplication() = 0;
    virtual void division() = 0;
    virtual ~operationsBase() {}
};

class operationsDerived : public operationsBase {
    int a, b;
public:
    operationsDerived(int x, int y) : a(x), b(y) {}
    void addition() override { cout << (a + b) << " "; }
    void subtraction() override { cout << (a - b) << " "; }
    void multiplication() override { cout << (a * b) << " "; }
    void division() override { cout << (a / b) << " "; }
};

int main() {
    int a, b;
    cin >> a >> b;
    operationsDerived obj(a, b);
    obj.addition();
    obj.subtraction();
    obj.multiplication();
    obj.division();
    return 0;
}