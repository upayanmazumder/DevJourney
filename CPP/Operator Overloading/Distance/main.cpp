#include <iostream>
using namespace std;

class Distance {
public:
    int feet, inches;

    Distance(int f, int i) {
        feet = f;
        inches = i;
    }

    Distance operator+(Distance d) {
        int totalInches = inches + d.inches;
        int extraFeet = totalInches / 12;
        return Distance(feet + d.feet + extraFeet, totalInches % 12);
    }

    void display() {
        cout << feet << " feet " << inches << " inches" << endl;
    }
};

int main() {
    Distance d1(5, 8), d2(3, 10);
    Distance d3 = d1 + d2;
    d3.display();
    return 0;
}
