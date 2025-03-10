#include <stdio.h>

int length(const char* str1) {
    int len = 0;
    while (str1[len] != '\0') {
        len++;
    }
    return len;
}

void count(const char* str1) {
    int alphabets = 0, numbers = 0, specialChars = 0;
    for (int i = 0; str1[i] != '\0'; i++) {
        if ((str1[i] >= 'A' && str1[i] <= 'Z') || (str1[i] >= 'a' && str1[i] <= 'z'))
            alphabets++;
        else if (str1[i] >= '0' && str1[i] <= '9')
            numbers++;
        else
            specialChars++;
    }
    printf("Alphabets: %d\n", alphabets);
    printf("Numbers: %d\n", numbers);
    printf("Special characters: %d\n", specialChars);
}

void occur(const char* str1) {
    int freq[128] = {0};  
    char uniqueChars[50]; 
    int uniqueIndex = 0;

    for (int i = 0; str1[i] != '\0'; i++) {
        char ch = str1[i];
        if (freq[(int)ch] == 0) { 
            uniqueChars[uniqueIndex++] = ch; 
        }
        freq[(int)ch]++;
    }

    for (int i = 0; i < uniqueIndex; i++) {
        printf("Occurrence of %c is %d\n", uniqueChars[i], freq[(int)uniqueChars[i]]);
    }
}

int main() {
    char message[51];  
    scanf("%50[^\n]", message);  

    printf("Length: %d\n", length(message));
    count(message);
    occur(message);

    return 0;
}