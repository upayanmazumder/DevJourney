#include <iostream>
using namespace std;

class Operation
{
public:
    int a, b;
    Operation(int x, int y) : a(x), b(y) {}
    void compute()
    {
        cout << "Addition: " << a + b << "\n";
        cout << "Difference: " << a - b << "\n";
        cout << "Product: " << a * b << "\n";
        if (b == 0)
        {
            cout << "Division by zero not possible";
            return;
        }
        cout << "Division: " << a / b << "\n";
        cout << "Modulus: " << a % b;
    }
};

int main()
{
    int x, y;
    cin >> x >> y;
    Operation op(x, y);
    op.compute();
    return 0;
}