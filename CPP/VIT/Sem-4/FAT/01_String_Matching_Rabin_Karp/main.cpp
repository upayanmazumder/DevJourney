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

    const int BASE = 256;
    const int MOD = 101;

    int power = 1;
    for (int i = 0; i < m - 1; i++)
    {
        power = (power * BASE) % MOD;
    }

    int patternHash = 0;
    int windowHash = 0;

    for (int i = 0; i < m; i++)
    {
        patternHash = (patternHash * BASE + pattern[i]) % MOD;
        windowHash = (windowHash * BASE + text[i]) % MOD;
    }

    bool found = false;

    for (int start = 0; start <= n - m; start++)
    {
        if (patternHash == windowHash)
        {
            bool same = true;
            for (int j = 0; j < m; j++)
            {
                if (text[start + j] != pattern[j])
                {
                    same = false;
                    break;
                }
            }

            if (same)
            {
                cout << "Pattern found at index " << start << "\n";
                found = true;
            }
        }

        if (start < n - m)
        {
            windowHash = (BASE * (windowHash - text[start] * power) + text[start + m]) % MOD;
            if (windowHash < 0)
            {
                windowHash += MOD;
            }
        }
    }

    if (!found)
    {
        cout << "Pattern not found.\n";
    }

    return 0;
}
