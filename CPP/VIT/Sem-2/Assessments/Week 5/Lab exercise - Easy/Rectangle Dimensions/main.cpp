#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length, breadth;

public:
    Rectangle(int l, int b) : length(l), breadth(b) {}

    friend void calcArea(Rectangle s);
};

void calcArea(Rectangle s)
{
    cout << s.length * s.breadth << endl;
}

int main()
{
    int length, breadth;
    cin >> length >> breadth;
    Rectangle r(length, breadth);
    calcArea(r);
    return 0;
}