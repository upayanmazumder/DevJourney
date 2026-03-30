#include <iostream>
using namespace std;

const long long INF = (1LL << 62);

void printOrder(int s[100][100], int i, int j)
{
    if (i == j)
    {
        cout << "A" << i;
        return;
    }

    cout << "(";
    printOrder(s, i, s[i][j]);
    cout << ",";
    printOrder(s, s[i][j] + 1, j);
    cout << ")";
}

int main()
{
    int n;

    if (!(cin >> n))
        return 0;

    long long p[101];

    for (int i = 0; i <= n; i++)
        cin >> p[i];

    long long m[100][100];
    int s[100][100];

    for (int i = 1; i <= n; i++)
        m[i][i] = 0;

    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            m[i][j] = INF;

            for (int k = i; k < j; k++)
            {
                long long q =
                    m[i][k] +
                    m[k + 1][j] +
                    p[i - 1] * p[k] * p[j];

                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << m[1][n] << endl;

    printOrder(s, 1, n);
    cout << endl;

    return 0;
}