#include <iostream>
using namespace std;

class Rectangle
{
    int l, w;
    static int count;

public:
    Rectangle(int x, int y) : l(x), w(y) { count++; }
    int getArea() { return l * w; }
    static int getCount() { return count; }
};

int Rectangle::count = 0;

int main()
{
    int n, x, y;
    cin >> n;
    Rectangle *rects[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        rects[i] = new Rectangle(x, y);
    }
    cout << "Total number of rectangles: " << Rectangle::getCount() << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Area of rectangle " << i + 1 << ": " << rects[i]->getArea() << endl;
        delete rects[i];
    }
    return 0;
}