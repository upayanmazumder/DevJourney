%{
#include <stdio.h>
int lines = 0, words = 0, chars = 0;
%}
%%
\n                             { lines++; chars++; }
[ \t]+                        { chars += yyleng; }
[a-zA-Z0-9]+                 { words++; chars += yyleng; }
.                            { chars++; }
%%
int yywrap(void) {
    return 1;
}
int main(void) {
    printf("Enter text (Ctrl+D then Enter to stop):\n");
    yylex();
    printf("Lines = %d\n", lines);
    printf("Words = %d\n", words);
    printf("Characters = %d\n", chars);
    return 0;
}
