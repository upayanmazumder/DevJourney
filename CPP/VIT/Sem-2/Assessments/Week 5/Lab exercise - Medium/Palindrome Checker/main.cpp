#include <iostream>
#include <algorithm>

using namespace std;

class PalindromeChecker
{
    string str;

public:
    PalindromeChecker(string s) : str(s) {}

    bool isPalindrome()
    {
        string temp = str;
        reverse(temp.begin(), temp.end());
        return temp == str;
    }

    ~PalindromeChecker()
    {
        cout << "Destructor called. Object destroyed." << endl;
    }
};

int main()
{
    string input;
    getline(cin, input);

    PalindromeChecker checker(input);

    if (checker.isPalindrome())
        cout << "The input string is a palindrome." << endl;
    else
        cout << "The input string is not a palindrome." << endl;

    return 0;
}