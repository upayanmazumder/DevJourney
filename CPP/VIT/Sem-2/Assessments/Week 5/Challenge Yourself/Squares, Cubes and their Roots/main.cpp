#include <iostream>
#include <cmath>
using namespace std;

class Demo {
public:
    int n;
    Demo(int x) : n(x) { cout << "Inside Constructor\n"; }
    ~Demo() { cout << "Inside Destructor\n"; }
    void display() {
        cout << "square = " << n * n << endl;
        cout << "square root = " << sqrt(n) << endl;
        cout << "cube = " << n * n * n << endl;
        cout << "cube root = " << cbrt(n) << endl;
    }
};

int main() {
    int n;
    cin >> n;
    Demo d(n);
    d.display();
}