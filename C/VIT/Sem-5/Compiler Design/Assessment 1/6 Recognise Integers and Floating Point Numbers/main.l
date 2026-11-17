%{
#include <stdio.h>
%}
%%
[0-9]+"."[0-9]+              { printf("FLOAT: %s\n", yytext); }
[0-9]+                       { printf("INTEGER: %s\n", yytext); }
[a-zA-Z]+                    { printf("WORD: %s\n", yytext); }
[ \t\n]+                     ;
.                            ;
%%
int yywrap(void) {
    return 1;
}
int main(void) {
    yylex();
    return 0;
}
