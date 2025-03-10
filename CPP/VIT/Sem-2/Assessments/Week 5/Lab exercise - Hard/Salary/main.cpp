#include <iostream>
#include <iomanip>
using namespace std;

void currentSalary(int **rate, int **salary)
{
    double newSalary = **salary + (**salary * **rate / 100.0);
    cout << fixed << setprecision(2) << newSalary << endl;
}

int main()
{
    int r, s;
    cin >> r >> s;
    int *pr = &r, *ps = &s;
    currentSalary(&pr, &ps);
    return 0;
}