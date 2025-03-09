#include <iostream>
using namespace std;

class A
{
    int N;

public:
    A(int n) : N(n) {}

    void generateSequence()
    {
        for (int i = 0; i < N; i++)
        {
            cout << (i % 6) + 1 << " ";
        }
    }
};

int main()
{
    int N;
    cin >> N;

    A obj(N);
    obj.generateSequence();
}