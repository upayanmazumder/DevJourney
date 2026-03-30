#include <iostream>
#include <string>
using namespace std;

string trim(const string &s)
{
    int i = 0;
    while (i < s.size() && s[i] == '0')
        i++;
    if (i == s.size())
        return "0";
    return s.substr(i);
}

string add(string a, string b)
{
    if (a.size() < b.size())
        swap(a, b);

    int carry = 0;
    string res = "";

    int i = a.size() - 1;
    int j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;

        if (i >= 0)
            sum += a[i--] - '0';
        if (j >= 0)
            sum += b[j--] - '0';

        res = char('0' + sum % 10) + res;
        carry = sum / 10;
    }

    return trim(res);
}

string sub(string a, string b) // assume a >= b
{
    int borrow = 0;
    string res = "";

    int i = a.size() - 1;
    int j = b.size() - 1;

    while (i >= 0)
    {
        int diff = (a[i] - '0') - borrow;

        if (j >= 0)
            diff -= (b[j] - '0');

        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
            borrow = 0;

        res = char('0' + diff) + res;

        i--;
        j--;
    }

    return trim(res);
}

string shift(string s, int k)
{
    if (s == "0")
        return s;
    return s + string(k, '0');
}

string karatsuba(string x, string y)
{
    x = trim(x);
    y = trim(y);

    if (x == "0" || y == "0")
        return "0";

    if (x.size() == 1 && y.size() == 1)
    {
        int p = (x[0] - '0') * (y[0] - '0');
        return to_string(p);
    }

    int n = max(x.size(), y.size());

    if (n % 2)
        n++;

    while (x.size() < n)
        x = "0" + x;
    while (y.size() < n)
        y = "0" + y;

    int m = n / 2;

    string a = x.substr(0, n - m);
    string b = x.substr(n - m);

    string c = y.substr(0, n - m);
    string d = y.substr(n - m);

    string z2 = karatsuba(a, c);
    string z0 = karatsuba(b, d);
    string z1 = karatsuba(add(a, b), add(c, d));

    string mid = sub(sub(z1, z2), z0);

    string res = add(add(shift(z2, 2 * m), shift(mid, m)), z0);

    return trim(res);
}

int main()
{
    string a, b;
    cin >> a >> b;

    cout << karatsuba(a, b) << endl;

    return 0;
}