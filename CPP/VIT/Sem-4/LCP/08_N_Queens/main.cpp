#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n;
vector<int> col;
vector<vector<string>> solutions;
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
