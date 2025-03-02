#include <stdio.h>

int main()
{
    int vCount = 0, cCount = 0, dCount = 0, sCount = 0;
    char s[150];
    int i, j, x;
    fgets(s, sizeof(s), stdin);

    for (i = 0; i < sizeof(s); i++)
    {
        x = (int)s[i];
        if ((s[i] == '\0') || (s[i] == ' '))
        {
            break;
        }
        if ((x >= 65) && (x <= 90))
        { // Uppercase Characters
            if ((s[i] == 'A') || (s[i] == 'E') || (s[i] == 'I') || (s[i] == 'O') || (s[i] == 'U'))
            {
                vCount++;
            }
            else
            {
                cCount++;
            }
        }
        else if ((x >= 97) && (x <= 121))
        { // Lowercase Characters
            if ((s[i] == 'a') || (s[i] == 'e') || (s[i] == 'i') || (s[i] == 'o') || (s[i] == 'u'))
            {
                vCount++;
            }
            else
            {
                cCount++;
            }
        }
        else if ((x >= 48) && (x <= 57))
        { // Digits
            dCount++;
        }
        else
        { // Special characters
            sCount++;
        }
    }
    printf("Vowels: %d\nConsonants: %d\nDigits: %d\nSpecial Characters: %d", vCount, cCount, dCount, sCount);
}