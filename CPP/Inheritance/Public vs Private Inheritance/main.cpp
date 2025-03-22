#include <iostream>
using namespace std;

class Parent {
public:
    int x = 10;
};

class ChildPublic : public Parent {};
class ChildPrivate : private Parent {};

int main() {
    ChildPublic obj1;
    cout << obj1.x << endl; // ✅ Allowed (public inheritance)

    ChildPrivate obj2;
    // cout << obj2.x; // ❌ Error: x is private in ChildPrivate

    return 0;
}
