#include <iostream>
#include <iomanip>
using namespace std;

class Circle {
protected:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getRadius() { return radius; }
};

class Cylinder : public Circle {
private:
    double height;
public:
    Cylinder(double r, double h) : Circle(r), height(h) {}
    void volume() { cout << fixed << setprecision(2) << 3.14 * radius * radius * height << endl; }
};

int main() {
    double r, h;
    cin >> r >> h;
    Cylinder c(r, h);
    c.volume();
}