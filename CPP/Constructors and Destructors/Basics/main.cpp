#include <iostream>
using namespace std;

class Test {
    public:
        Test() {
            cout << "Constructor called!" << endl;
        }
        ~Test() {
            cout << "Destructor called!" << endl;
        }
};

int main() {
    Test obj;  // Constructor called automatically
    return 0;  // Destructor called automatically when obj goes out of scope
}
