#include <iostream>
using namespace std;

class Wall
{
private:
    double length, height;

public:
    Wall(double l, double h) : length(l), height(h) {}

    double calculateArea()
    {
        return length * height;
    }
};

int main()
{
    double length1, height1, length2, height2;

    cin >> length1 >> height1 >> length2 >> height2;

    Wall wall1(length1, height1);
    Wall wall2(length2, height2);

    cout << "Area of Wall 1: " << wall1.calculateArea() << endl;
    cout << "Area of Wall 2: " << wall2.calculateArea() << endl;
}