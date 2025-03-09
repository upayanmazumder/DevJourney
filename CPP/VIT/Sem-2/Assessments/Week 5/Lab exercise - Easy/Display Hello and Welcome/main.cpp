#include <iostream>
using namespace std;

void displayWelcome(const string &name = "")
{
    cout << "Welcome";
    if (!name.empty())
    {
        cout << " " << name;
    }
    cout << endl;
}

void displayHello(const string &name = "")
{
    cout << "Hello";
    if (!name.empty())
    {
        cout << " " << name;
    }
    cout << endl;
}

int main()
{
    string name;
    getline(cin, name);

    displayWelcome(name);
    displayHello(name);

    return 0;
}