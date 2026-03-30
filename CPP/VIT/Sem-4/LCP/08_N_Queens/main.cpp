#include <iostream>
#include <string>
using namespace std;

int n;
int col[20];
int solCount = 0;

bool ok(int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        int d = col[i] - c;
        if (d < 0)
            d = -d;

        if (col[i] == c || d == r - i)
            return false;
    }
    return true;
}

void printBoard()
{
    solCount++;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (col[i] == j)
                cout << "Q";
            else
                cout << ".";
        }
        cout << "\n";
    }

    cout << "\n";
}

void place(int r)
{
    if (r == n)
    {
        printBoard();
        return;
    }

    for (int c = 0; c < n; c++)
    {
        if (ok(r, c))
        {
            col[r] = c;
            place(r + 1);
        }
    }
}

int main()
{
    cin >> n;

    place(0);

    cout << "Total solutions: " << solCount << "\n";

    return 0;
}