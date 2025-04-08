#include <iostream>
using namespace std;

class Shape {
public:
    double base, height;
    void get(double b, double h) {
        base = b;
        height = h;
    }

    virtual void area() = 0;
};

class Triangle : public Shape {
public:
    void area() override {
        cout << "Area of Triangle: " << (0.5 * base * height) << endl;
    }
};

class Rectangle : public Shape {
public:
    void area() override {
        cout << "Area of Rectangle: " << (base * height) << endl;
    }
};

class Calculator {
    int value;
public:
    Calculator() : value(0) {}

    void add(int a) {
        value += a;
        cout << "Added int: " << a << ", Total: " << value << endl;
    }

    void add(double d) {
        value += static_cast<int>(d);
        cout << "Added double (as int): " << d << ", Total: " << value << endl;
    }

    void add(int a, int b) {
        value += (a + b);
        cout << "Added two ints: " << a + b << ", Total: " << value << endl;
    }

    void operator+(int a) {
        value += a;
        cout << "Operator + with int: Total = " << value << endl;
    }

    friend Calculator operator+(Calculator c1, Calculator c2);

    void show() {
        cout << "Final Value: " << value << endl;
    }
};


Calculator operator+(Calculator c1, Calculator c2) {
    Calculator temp;
    temp.value = c1.value + c2.value;
    return temp;
}

int main() {
    cout << "===== FUNCTION OVERLOADING DEMO =====" << endl;
    Calculator calc1;
    calc1.add(10);
    calc1.add(5.7);
    calc1.add(3, 7);
    calc1 + 8;

    cout << "\n===== OPERATOR OVERLOADING WITH OBJECTS =====" << endl;
    Calculator calc2;
    calc2.add(15);
    Calculator result = calc1 + calc2;
    result.show();

    cout << "\n===== RUNTIME POLYMORPHISM (Virtual Functions) =====" << endl;
    Shape* s;

    Triangle t;
    s = &t;
    s->get(10, 5);
    s->area();

    Rectangle r;
    s = &r;
    s->get(10, 4);
    s->area();

    return 0;
}
