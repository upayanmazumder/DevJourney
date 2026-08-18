#include <stdio.h>
#include <string.h>

int main()
{
    char data[100], gen[30];
    int i, j, n, m;

    printf("Enter data: ");
    scanf("%s", data);

    printf("Enter generator: ");
    scanf("%s", gen);

    n = strlen(data);
    m = strlen(gen);

    for (i = 0; i < m - 1; i++)
        data[n + i] = '0';
    data[n + m - 1] = '\0';

    for (i = 0; i < n; i++)
        if (data[i] == '1')
            for (j = 0; j < m; j++)
                data[i + j] =
                    (data[i + j] == gen[j]) ? '0' : '1';

    printf("CRC: %s\n", data + n);

    return 0;
}