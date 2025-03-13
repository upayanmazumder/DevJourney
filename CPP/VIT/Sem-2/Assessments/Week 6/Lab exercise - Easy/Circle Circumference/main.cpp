#include <iostream>
#include <iomanip>

using namespace std;

class Circle {
protected:
    double radius;

public:
    Circle(double r) : radius(r) {}
};

class Class1 : public Circle {
public:
    Class1(double r) : Circle(r) {}

    void calculateCircumference() {
        double circumference = 2 * 3.14159 * radius;
        cout << "Class 1: " << fixed << setprecision(2) << circumference << endl;
    }
};

class Class2 : public Circle {
public:
    Class2(double r) : Circle(r) {}

    void calculateCircumference() {
        double circumference = 23.14 * radius;
        cout << "Class 2: " << fixed << setprecision(2) << circumference << endl;
    }
};

int main() {
    double radius;
    cin >> radius;

    Class1 obj1(radius);
    Class2 obj2(radius);

    obj1.calculateCircumference();
    obj2.calculateCircumference();

    return 0;
}