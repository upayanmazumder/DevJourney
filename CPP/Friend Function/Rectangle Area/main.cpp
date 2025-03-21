#include <iostream>
using namespace std;

class Rectangle {
private:
    int width, height;

public:
    Rectangle(int w, int h) { width = w; height = h; }
    friend int area(Rectangle r);
};

int area(Rectangle r) {
    return r.width * r.height;
}

int main() {
    Rectangle rect(5, 10);
    cout << "Area: " << area(rect) << endl;
    return 0;
}
