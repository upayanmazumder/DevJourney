#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ALT 10
#define MAX_LEN 20

int main() {
    char headSym;
    char alts[MAX_ALT][MAX_LEN];
    char recPart[MAX_ALT][MAX_LEN];
    char basePart[MAX_ALT][MAX_LEN];
    int altCount = 0, recCount = 0, baseCount = 0;
    char buf[100];

    printf("Enter production rule (e.g., E -> E+T | T):\n");
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

    for (pos = 0; pos < altCount; pos++) {
        if (alts[pos][0] == headSym) {
            strcpy(recPart[recCount++], &alts[pos][1]);
        } else {
            strcpy(basePart[baseCount++], alts[pos]);
        }
    }

    printf("\n================ OUTPUT GRAMMAR ================\n");

    if (recCount == 0) {
        printf("The grammar has no direct left recursion.\n");
    } else {
        printf("%c -> ", headSym);

        for (pos = 0; pos < baseCount; pos++) {
            printf("%s%c'", basePart[pos], headSym);
            if (pos < baseCount - 1)
                printf(" | ");
        }

        printf("\n");

        printf("%c' -> ", headSym);

        for (pos = 0; pos < recCount; pos++) {
            printf("%s%c'", recPart[pos], headSym);
            if (pos < recCount - 1)
                printf(" | ");
        }

        printf(" | #\n");
    }

    printf("================================================\n");

    return 0;
}
