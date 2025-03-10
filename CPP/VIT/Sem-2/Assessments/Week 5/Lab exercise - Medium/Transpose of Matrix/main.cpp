#include <iostream>
#include <vector>
using namespace std;

class Matrix
{
public:
    int r, c;
    vector<vector<int>> m;

    Matrix(int r, int c) : r(r), c(c), m(r, vector<int>(c)) {}

    void setElements()
    {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> m[i][j];
    }

    void print()
    {
        for (auto &row : m)
        {
            for (int x : row)
                cout << x << " ";
            cout << endl;
        }
    }

    Matrix transpose()
    {
        Matrix t(c, r);
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                t.m[j][i] = m[i][j];
        return t;
    }
};

int main()
{
    int r, c;
    cin >> r >> c;
    Matrix m(r, c);
    m.setElements();
    cout << "Original Matrix:\n";
    m.print();
    cout << "Transposed Matrix:\n";
    m.transpose().print();
    return 0;
}