#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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
            m[i][j] = LLONG_MAX;
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
    function<void(int, int)> printOrder = [&](int i, int j)
    { if(i==j) cout<<"A"<<i; else{ cout<<"("; printOrder(i, s[i][j]); cout<<","; printOrder(s[i][j]+1, j); cout<<")"; } };
    printOrder(1, n);
    cout << "\n";
    return 0;
}
