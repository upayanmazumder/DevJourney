#include <stdio.h>
#include <string.h>

int longestPalindrome(char s[])
{
    int n = strlen(s);
    int maxLength = 1;
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            int isPalindrome = 1;
            for (k = 0; k < (j + i + 1) / 2; k++)
            {
                if (s[i + k] != s[j - k])
                {
                    isPalindrome = 0;
                    break;
                }
            }
            if (isPalindrome && (j - i + 1) > maxLength)
            {
                maxLength = j - i + 1;
            }
        }
    }
    return maxLength;
}

int main()
{
    char s[51];
    scanf("%s", s);
    int result = longestPalindrome(s);
    printf("%d\n", result);
}