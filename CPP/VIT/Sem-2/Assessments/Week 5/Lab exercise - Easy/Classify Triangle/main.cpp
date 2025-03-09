#include <iostream>
using namespace std;

class Triangle
{
private:
    int a, b, c;

public:
    Triangle(int x, int y, int z) : a(x), b(y), c(z) {}

    void classifyTriangle()
    {
        if (a == b && b == c)
        {
            cout << "Equilateral triangle" << endl;
        }
        else if (a == b || b == c || a == c)
        {
            cout << "Isosceles triangle" << endl;
        }
        else
        {
            cout << "Scalene triangle" << endl;
        }
    }
};

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    Triangle t(a, b, c);
    t.classifyTriangle();
}