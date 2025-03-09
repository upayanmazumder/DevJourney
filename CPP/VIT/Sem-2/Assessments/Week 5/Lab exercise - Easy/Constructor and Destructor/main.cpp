#include <iostream>
using namespace std;

class Man
{
    static int count;
    int id;

public:
    Man()
    {
        id = count++;
        cout << "Created " << id + 1 << endl;
    }

    ~Man()
    {
        cout << "Destroyed " << --count << endl;
    }
};

int Man::count = 0;

int main()
{
    int n;
    std::cin >> n;

    Man *arr = new Man[n];

    delete[] arr;
}