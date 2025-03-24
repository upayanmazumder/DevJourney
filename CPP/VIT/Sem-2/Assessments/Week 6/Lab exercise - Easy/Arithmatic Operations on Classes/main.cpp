#include <iostream>
#include <iomanip>
using namespace std;

class Parent {
public:
    void add(int a, int b) { cout << a + b << endl; }
};

class Child1 : public Parent {
public:
    void sub(int a, int b) { cout << a - b << endl; }
};

class Child2 : public Parent {
public:
    void mul(int a, int b) { cout << a * b << endl; }
};

class Child3 : public Parent {
public:
    void div(int a, int b) { cout << fixed << setprecision(2) << (double)a / b << endl; }
};

int main() {
    int a, b;
    cin >> a >> b;
    Child3 obj;
    obj.add(a, b);
    Child1().sub(a, b);
    Child2().mul(a, b);
    obj.div(a, b);
}