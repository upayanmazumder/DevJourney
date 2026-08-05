%{
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ALT 10
#define MAX_LEN 20

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
    char recPart[MAX_ALT][MAX_LEN];
    char basePart[MAX_ALT][MAX_LEN];
    int recCount = 0, baseCount = 0;

    printf("Enter production rule (e.g., E -> E+T | T):\n");

    yylex();

    for (int pos = 0; pos < altCount; pos++) {
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

        for (int pos = 0; pos < baseCount; pos++) {
            printf("%s%c'", basePart[pos], headSym);
            if (pos < baseCount - 1)
                printf(" | ");
        }

        printf("\n");

        printf("%c' -> ", headSym);

        for (int pos = 0; pos < recCount; pos++) {
            printf("%s%c'", recPart[pos], headSym);
            if (pos < recCount - 1)
                printf(" | ");
        }

        printf(" | #\n");
    }

    printf("================================================\n");

    return 0;
}
