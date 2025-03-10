#include <iostream>
#include <iomanip>
using namespace std;

class Circle {
    double r;
    static int circleCount;
public:
    Circle(double x) : r(x) { circleCount++; }
    static int getCircleCount() { return circleCount; }
    double calculateArea() { return 3.14159 * r * r; }
    double calculateCircumference() { return 2 * 3.14159 * r; }
    void displayDetails() {
        cout << "Radius: " << fixed << setprecision(2) << r << endl;
        cout << "Area: " << calculateArea() << endl;
        cout << "Circumference: " << calculateCircumference() << endl;
    }
};

int Circle::circleCount = 0;

int main() {
    int n;
    cin >> n;
    cout << n << endl;
    while (n--) {
        double r;
        cin >> r;
        Circle c(r);
        c.displayDetails();
    }
}