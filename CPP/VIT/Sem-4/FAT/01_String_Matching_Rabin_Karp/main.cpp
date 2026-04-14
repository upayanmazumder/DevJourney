#include <iostream>
#include <string>

using namespace std;

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

    // Base for characters and a small prime modulus for hash.
    const int d = 256;
    const int q = 101;

    int h = 1;
    for (int i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }

    int pHash = 0; // hash of pattern
    int tHash = 0; // hash of current text window

    for (int i = 0; i < m; i++)
    {
        pHash = (d * pHash + pattern[i]) % q;
        tHash = (d * tHash + text[i]) % q;
    }

    bool found = false;
    for (int i = 0; i <= n - m; i++)
    {
        // If hashes match, verify character by character to avoid collision issue.
        if (pHash == tHash)
        {
            bool same = true;
            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    same = false;
                    break;
                }
            }
            if (same)
            {
                cout << "Pattern found at index " << i << "\n";
                found = true;
            }
        }

        // Roll hash to the next window.
        if (i < n - m)
        {
            tHash = (d * (tHash - text[i] * h) + text[i + m]) % q;
            if (tHash < 0)
            {
                tHash += q;
            }
        }
    }

    if (!found)
    {
        cout << "Pattern not found.\n";
    }

    return 0;
}
