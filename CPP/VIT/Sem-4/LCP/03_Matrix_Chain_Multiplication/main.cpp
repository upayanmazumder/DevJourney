#include <iostream>
#include <vector>
using namespace std;

const long long INF = (1LL << 62);

void printOrder(const vector<vector<int>> &s, int i, int j)
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
    vector<long long> p(n + 1);
    for (int i = 0; i <= n; i++)
        cin >> p[i];
    vector<vector<long long>> m(n + 2, vector<long long>(n + 2, 0));
    vector<vector<int>> s(n + 2, vector<int>(n + 2, 0));
    for (int len = 2; len <= n; ++len)
    {
        for (int i = 1; i <= n - len + 1; ++i)
        {
            int j = i + len - 1;
            m[i][j] = INF;
            for (int k = i; k < j; ++k)
            {
                long long q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << m[1][n] << "\n";
    printOrder(s, 1, n);
    cout << "\n";
    return 0;
}
