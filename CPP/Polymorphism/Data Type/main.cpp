#include <iostream>
using namespace std;

class Num {
public:
    void Tell(int x) {
        cout << "Integer";
    }

    void Tell(float x) {
        cout << "Float";
    }
};

int main() {
    Num n;
    int c;
    cout << "Enter 1 for integer and 2 for float: ";
    cin >> c;
    if (c == 1) {
        int x;
        cin >> x;
        n.Tell(x);
    } else {
        float x;
        cin >> x;
        n.Tell(x);
    }
}