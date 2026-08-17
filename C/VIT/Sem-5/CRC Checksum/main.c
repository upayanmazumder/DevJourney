#include <stdio.h>
#include <string.h>

int main()
{
    char data[100], key[30], temp[130];
    int n, k, i, j;

    printf("Enter data: ");
    scanf("%s", data);

    printf("Enter generator: ");
    scanf("%s", key);

    n = strlen(data);
    k = strlen(key);

    strcpy(temp, data);

    // Append k-1 zeros
    for (i = 0; i < k - 1; i++)
        temp[n + i] = '0';
    temp[n + k - 1] = '\0';

    // XOR division
    for (i = 0; i < n; i++)
    {
        if (temp[i] == '1')
        {
            for (j = 0; j < k; j++)
                temp[i + j] ^= key[j] ^ '0';
        }
    }

    printf("CRC: ");
    for (i = n; i < n + k - 1; i++)
        printf("%c", temp[i]);

    printf("\nCodeword: %s", data);

    for (i = n; i < n + k - 1; i++)
        printf("%c", temp[i]);

    printf("\n");

    return 0;
}