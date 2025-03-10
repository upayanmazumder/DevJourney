#include <iostream>
#include <iomanip>
using namespace std;

class Area
{
    int s, l, b;
    float r, base, h;

public:
    void get();
    inline void squareArea();
    inline void rectangleArea();
    inline void circleArea();
    inline void parallelogramArea();
};

void Area::get() { cin >> s >> l >> b >> r >> base >> h; }
inline void Area::squareArea() { cout << "Area of the square: " << s * s << endl; }
inline void Area::rectangleArea() { cout << "Area of the rectangle: " << l * b << endl; }
inline void Area::circleArea() { cout << "Area of the circle: " << fixed << setprecision(2) << 3.14 * r * r << endl; }
inline void Area::parallelogramArea() { cout << "Area of the parallelogram: " << fixed << setprecision(2) << base * h << endl; }

int main()
{
    Area a;
    a.get();
    a.squareArea();
    a.rectangleArea();
    a.circleArea();
    a.parallelogramArea();
}