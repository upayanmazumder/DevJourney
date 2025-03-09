#include <iostream>
using namespace std;

class Box
{
private:
    int length;

public:
    Box() : length(0) {}

    void get()
    {
        cin >> length;
    }

    friend int printVolume(Box b);
};

int printVolume(Box b)
{
    return b.length * b.length * b.length;
}

int main()
{
    Box b;
    b.get();
    cout << printVolume(b) << endl;
    return 0;
}