#include <iostream>
using namespace std;

class Demo
{
    static int X, Y;

public:
    static void fun()
    {
        cout << "Value of X: " << X << endl;
        cout << "Value of Y: " << Y << endl;
    }

    static void get(int newX, int newY)
    {
        X = newX;
        Y = newY;
    }
};

int Demo::X = 10;
int Demo::Y = 20;

int main()
{
    Demo::fun();
    int x, y;
    cin >> x >> y;
    Demo::get(x, y);
    Demo::fun();
    return 0;
}