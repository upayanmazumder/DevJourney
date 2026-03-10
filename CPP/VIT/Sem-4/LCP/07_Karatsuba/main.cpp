#include <iostream>
#include <string>
using namespace std;
string rev(string s)
{
    int i = 0, j = (int)s.size() - 1;
    while (i < j)
    {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
        ++i;
        --j;
    }
    return s;
}
string trimZ(const string &s)
{
    size_t i = 0;
    while (i < s.size() && s[i] == '0')
        ++i;
    return (i == s.size()) ? "0" : s.substr(i);
}
string addS(string a, string b)
{
    a = rev(a);
    b = rev(b);
    int n = (a.size() > b.size()) ? (int)a.size() : (int)b.size(), carry = 0;
    string r;
    for (int i = 0; i < n; i++)
    {
        int da = (i < a.size() ? a[i] - '0' : 0);
        int db = (i < b.size() ? b[i] - '0' : 0);
        int s = da + db + carry;
        r.push_back(char('0' + (s % 10)));
        carry = s / 10;
    }
    if (carry)
        r.push_back(char('0' + carry));
    r = rev(r);
    return trimZ(r);
}
string subS(string a, string b)
{ // a>=b
    a = rev(a);
    b = rev(b);
    int n = a.size(), borrow = 0;
    string r;
    for (int i = 0; i < n; i++)
    {
        int da = a[i] - '0';
        int db = (i < b.size() ? b[i] - '0' : 0);
        int s = da - db - borrow;
        if (s < 0)
        {
            s += 10;
            borrow = 1;
        }
        else
            borrow = 0;
        r.push_back(char('0' + s));
    }
    while (r.size() > 1 && r.back() == '0')
        r.pop_back();
    r = rev(r);
    return trimZ(r);
}
string karatsuba(string x, string y)
{
    x = trimZ(x);
    y = trimZ(y);
    if (x == "0" || y == "0")
        return "0";
    if (x.size() == 1 && y.size() == 1)
    {
        int p = (x[0] - '0') * (y[0] - '0');
        return to_string(p);
    }
    int n = (x.size() > y.size()) ? (int)x.size() : (int)y.size();
    if (n % 2)
        ++n;
    while (x.size() < n)
        x = string("0") + x;
    while (y.size() < n)
        y = string("0") + y;
    int m = n / 2;
    string xh = x.substr(0, n - m), xl = x.substr(n - m);
    string yh = y.substr(0, n - m), yl = y.substr(n - m);
    string z2 = karatsuba(xh, yh);
    string z0 = karatsuba(xl, yl);
    string z1 = karatsuba(addS(xh, xl), addS(yh, yl));
    string mid = subS(subS(z1, z2), z0);
    string res = z2 + string(2 * m, '0');
    if (mid != "0")
        res = addS(res, mid + string(m, '0'));
    res = addS(res, z0);
    return trimZ(res);
}
int main()
{

    string a, b;
    if (!(cin >> a >> b))
        return 0;
    cout << karatsuba(a, b) << "\n";
    return 0;
}
