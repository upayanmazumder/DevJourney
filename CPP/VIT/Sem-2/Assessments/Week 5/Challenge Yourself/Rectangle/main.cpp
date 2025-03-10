#include <iostream>
#include <cmath>
using namespace std;

class Rectangle {
    int llx, lly, urx, ury;
public:
    Rectangle(int a, int b, int c, int d) : llx(a), lly(b), urx(c), ury(d) {
        cout << "Rectangle created." << endl;
    }
    ~Rectangle() { cout << "Rectangle destroyed." << endl; }
    void area() { cout << "Area of the rectangle: " << abs(urx - llx) * abs(ury - lly) << endl; }
};

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    Rectangle r(a, b, c, d);
    r.area();
}