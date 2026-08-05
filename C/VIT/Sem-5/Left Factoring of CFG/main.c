#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ALT 10
#define MAX_LEN 30

int main() {
    char headSym;
    char alts[MAX_ALT][MAX_LEN];
    int altCount = 0;
    char buf[100];

    printf("Enter a production rule (e.g., A -> aB1 | aB2 | c):\n");

    if (fgets(buf, sizeof(buf), stdin) == NULL)
        return 1;

    int pos = 0;

    while (buf[pos] == ' ' || buf[pos] == '\t')
        pos++;

    headSym = buf[pos++];

    while (buf[pos] != '\0' &&
           (buf[pos] == ' ' || buf[pos] == '-' ||
            buf[pos] == '>' || buf[pos] == '=')) {
        pos++;
    }

    char *word = strtok(&buf[pos], "|\n");

    while (word != NULL) {
        while (*word == ' ' || *word == '\t')
            word++;

        int wlen = strlen(word);

        while (wlen > 0 &&
               (word[wlen - 1] == ' ' ||
                word[wlen - 1] == '\t' ||
                word[wlen - 1] == '\r')) {
            word[wlen - 1] = '\0';
            wlen--;
        }

        if (strlen(word) > 0)
            strcpy(alts[altCount++], word);

        word = strtok(NULL, "|\n");
    }

    if (altCount <= 1) {
        printf("\n================ OUTPUT GRAMMAR ================\n");
        printf("No common prefix to factor.\n");
        printf("================================================\n");
        return 0;
    }

    char common[MAX_LEN] = "";
    int commonLen = 0;
    int stillMatch = 1;

    while (stillMatch) {
        char ch = alts[0][commonLen];

        if (ch == '\0')
            break;

        for (pos = 1; pos < altCount; pos++) {
            if (alts[pos][commonLen] != ch) {
                stillMatch = 0;
                break;
            }
        }

        if (stillMatch) {
            common[commonLen] = ch;
            commonLen++;
        }
    }

    common[commonLen] = '\0';

    while (commonLen > 0 &&
           (common[commonLen - 1] == ' ' ||
            common[commonLen - 1] == '\t')) {
        common[commonLen - 1] = '\0';
        commonLen--;
    }

    printf("\n================ OUTPUT GRAMMAR ================\n");

    if (commonLen == 0) {
        printf("No common prefix found among the alternatives.\n");
    } else {
        printf("%c -> %s %c'\n", headSym, common, headSym);

        printf("%c' -> ", headSym);

        for (pos = 0; pos < altCount; pos++) {
            char *tail = &alts[pos][commonLen];

            while (*tail == ' ' || *tail == '\t')
                tail++;

            if (strlen(tail) == 0)
                printf("#");
            else
                printf("%s", tail);

            if (pos < altCount - 1)
                printf(" | ");
        }

        printf("\n");
    }

    printf("================================================\n");

    return 0;
}
