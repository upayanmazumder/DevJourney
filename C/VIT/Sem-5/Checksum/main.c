#include <stdio.h>

int main()
{
    int n, i, sum = 0, x;

    printf("Enter number of data blocks: ");
    scanf("%d", &n);

    printf("Enter data blocks (decimal): ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        sum += x;
    }

    while (sum > 255)
        sum = (sum & 255) + (sum >> 8);

    printf("Checksum: %d\n", (~sum) & 255);

    return 0;
}