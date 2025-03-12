#include <stdio.h>

int findSumOfMaxMinDigits (int *num) {
    int minDigit = 9, maxDigit = 0, digit;
    int n = *num;
    while (n) {
        digit = n % 10;
        if (digit > maxDigit ) {
            maxDigit = digit;
        }
        if (digit < minDigit ) {
            minDigit = digit;
        }
        n /= 10;
    }
    return minDigit + maxDigit;
}

int main() {
    int n;
    scanf("%d", &n);
    if (n <= 1000) {
        printf("Invalid input");
    } else {
        int result = findSumOfMaxMinDigits(&n);
        printf("%d\n",result);
    }
}