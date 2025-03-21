#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() { cout << "Drawing a shape\n"; }
};

class Circle : public Shape {
public:
    void draw() override { cout << "Drawing a circle\n"; }
};

class Square : public Shape {
public:
    void draw() override { cout << "Drawing a square\n"; }
};

int main() {
    Shape *s;
    Circle c;
    Square sq;

    s = &c;
    s->draw(); // Calls Circle's draw()

    s = &sq;
    s->draw(); // Calls Square's draw()

    return 0;
}
