%{
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ALT 10
#define MAX_LEN 30

char alts[MAX_ALT][MAX_LEN];
int altCount = 0;
char headSym = 0;

void store_alt(char *txt) {
    while (*txt == ' ' || *txt == '\t')
        txt++;
    int L = strlen(txt);
    while (L > 0 && (txt[L - 1] == ' ' || txt[L - 1] == '\t' || txt[L - 1] == '\r')) {
        txt[--L] = '\0';
    }
    if (L > 0)
        strcpy(alts[altCount++], txt);
}
%}

%x ALTS

%%
<INITIAL>[A-Za-z][A-Za-z0-9']*   { headSym = yytext[0]; }
<INITIAL>"->"|"="                { BEGIN(ALTS); }
<INITIAL>[ \t]                   { }
<ALTS>[^|\n]+                    { store_alt(yytext); }
<ALTS>"|"                        { }
<ALTS>\n                         { return 0; }
\n                                { return 0; }
%%

int yywrap(void) {
    return 1;
}

int main(void) {
    printf("Enter a production rule (e.g., A -> aB1 | aB2 | c):\n");

    yylex();

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

        for (int pos = 1; pos < altCount; pos++) {
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

    while (commonLen > 0 && (common[commonLen - 1] == ' ' || common[commonLen - 1] == '\t')) {
        common[--commonLen] = '\0';
    }

    printf("\n================ OUTPUT GRAMMAR ================\n");

    if (commonLen == 0) {
        printf("No common prefix found among the alternatives.\n");
    } else {
        printf("%c -> %s %c'\n", headSym, common, headSym);

        printf("%c' -> ", headSym);

        for (int pos = 0; pos < altCount; pos++) {
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
