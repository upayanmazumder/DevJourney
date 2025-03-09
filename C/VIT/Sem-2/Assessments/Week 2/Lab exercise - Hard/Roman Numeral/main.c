#include <stdio.h>
#include <string.h>

int convert(int num, char *result)
{
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int i = 0;
    for (int j = 0; j < 13; j++)
    {
        while (num >= values[j])
        {
            num -= values[j];
            strcpy(result + i, symbols[j]);
            i += strlen(symbols[j]);
        }
    }
    result[i] = '\0';
    return 0;
}

int main()
{
    int number;
    char roman[100];
    scanf("%d", &number);
    if (number <= 0)
    {
        printf("Invalid");
        return 1;
    }
    convert(number, roman);
    printf("%s", roman);
    return 0;
}