#include <iostream>
#include <vector>
#include <climits>
using namespace std;
struct Res

{
    long long sum;
    int l, r;
};
Res maxCross(vector<long long> &a, int l, int m, int r)

{
    long long left_sum = LLONG_MIN, sum = 0;
    int maxl = m;
    for (int i = m; i >= l; i--)
    {
        sum += a[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            maxl = i;
        }
    }
    long long right_sum = LLONG_MIN;
    sum = 0;
    int maxr = m + 1;
    for (int i = m + 1; i <= r; i++)
    {
        sum += a[i];
        if (sum > right_sum)
        {
            right_sum = sum;
            maxr = i;
        }
    }
    return {left_sum + right_sum, maxl, maxr};
}
Res maxSub(vector<long long> &a, int l, int r)
{
    if (l == r)
        return {a[l], l, r};
    int m = (l + r) / 2;
    Res left = maxSub(a, l, m);
    Res right = maxSub(a, m + 1, r);
    Res cross = maxCross(a, l, m, r);
    if (left.sum >= right.sum && left.sum >= cross.sum)
        return left;
    if (right.sum >= left.sum && right.sum >= cross.sum)
        return right;
    return cross;
}
int main()
{
    int n;
    if (!(cin >> n))
        return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Res r = maxSub(a, 0, n - 1);
    cout << r.sum << "\n"
         << r.l << " " << r.r << "\n";
    return 0;
}
