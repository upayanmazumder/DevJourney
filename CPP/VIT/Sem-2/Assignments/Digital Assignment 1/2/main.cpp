#include <iostream>
using namespace std;

class Room2;

class Room1 {
    float length, breadth;
public:
    Room1() {
        cout << "Enter Room1 details in m\n";
        cout << "\tLength: ";
        cin >> length;
        cout << "\tBreadth: ";
        cin >> breadth;
    }
    friend float totalArea(Room1, Room2);
};

class Room2 {
    float length, breadth;
public:
    Room2(float l, float b) {
        length = l;
        breadth = b;
    }
    friend float totalArea(Room1, Room2);
};

float totalArea(Room1 r1, Room2 r2) {
    float area1 = r1.length * 3.2808 * r1.breadth * 3.2808;
    float area2 = r2.length * r2.breadth;
    return area1 + area2;
}

int main() {
    float l, b;
    Room1 r1;
    cout << "Enter Room2 details in ft\n";
    cout << "\tLength: ";
    cin >> l;
    cout << "\tBreadth: ";
    cin >> b;
    Room2 r2(l, b);
    cout << "Total area: " << totalArea(r1, r2) << " square feet" << endl;
    return 0;
}
