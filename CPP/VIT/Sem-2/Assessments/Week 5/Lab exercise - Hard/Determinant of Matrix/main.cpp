#include <iostream>
using namespace std;

class Matrix
{
public:
    int n, **m;

    Matrix(int size) : n(size)
    {
        m = new int *[n];
        for (int i = 0; i < n; i++)
            m[i] = new int[n];
    }

    void readMatrix()
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> m[i][j];
    }

    void displayMatrix()
    {
        cout << "Matrix:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << m[i][j] << " ";
            cout << endl;
        }
    }

    int determinant()
    {
        if (n == 1)
            return m[0][0];
        if (n == 2)
            return m[0][0] * m[1][1] - m[0][1] * m[1][0];

        int det = 0;
        for (int i = 0; i < n; i++)
        {
            Matrix sub(n - 1);
            for (int j = 1; j < n; j++)
                for (int k = 0, col = 0; k < n; k++)
                    if (k != i)
                        sub.m[j - 1][col++] = m[j][k];
            det += (i % 2 == 0 ? 1 : -1) * m[0][i] * sub.determinant();
        }
        return det;
    }

    ~Matrix()
    {
        for (int i = 0; i < n; i++)
            delete[] m[i];
        delete[] m;
    }
};

int main()
{
    int n;
    cin >> n;
    Matrix mat(n);
    mat.readMatrix();
    mat.displayMatrix();
    cout << "Determinant: " << mat.determinant();
    return 0;
}