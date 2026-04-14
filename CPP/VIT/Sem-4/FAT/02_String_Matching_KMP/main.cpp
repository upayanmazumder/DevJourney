#include <iostream>
#include <string>

using namespace std;

void computeLPS(const string &pattern, int *lps)
{
    int m = (int)pattern.length();
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main()
{
    string text, pattern;

    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter pattern: ";
    getline(cin, pattern);

    int n = (int)text.length();
    int m = (int)pattern.length();

    if (m == 0 || m > n)
    {
        cout << "No valid match possible.\n";
        return 0;
    }

    int *lps = new int[m];
    computeLPS(pattern, lps);

    int i = 0; // text index
    int j = 0; // pattern index
    bool found = false;

    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            cout << "Pattern found at index " << (i - j) << "\n";
            found = true;
            j = lps[j - 1];
        }
        else if (i < n && text[i] != pattern[j])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    if (!found)
    {
        cout << "Pattern not found.\n";
    }

    delete[] lps;
    return 0;
}
