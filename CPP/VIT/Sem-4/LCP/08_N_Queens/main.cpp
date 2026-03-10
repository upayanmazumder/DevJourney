#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> col;
vector<vector<string>> solutions;
bool ok(int r, int c)
{
    for (int i = 0; i < r; i++)
        if (col[i] == c || abs(col[i] - c) == r - i)
            return false;
    return true;
}
void place(int r)
{
    if (r == n)
    {
        vector<string> board(n, string(n, '.'));
        for (int i = 0; i < n; i++)
            board[i][col[i]] = 'Q';
        solutions.push_back(board);
        return;
    }
    for (int c = 0; c < n; c++)
        if (ok(r, c))
        {
            col[r] = c;
            place(r + 1);
        }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!(cin >> n))
        return 0;
    col.assign(n, -1);
    place(0);
    cout << solutions.size() << "\n";
    for (auto &bd : solutions)
    {
        for (auto &row : bd)
            cout << row << "\n";
        cout << "\n";
    }
    return 0;
}
