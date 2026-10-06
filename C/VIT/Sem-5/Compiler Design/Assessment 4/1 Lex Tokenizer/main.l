%{
#include <stdio.h>
%}

%%
[A-Za-z_][A-Za-z0-9_]*  printf("IDENTIFIER: %s\n", yytext);
[0-9]+(\.[0-9]+)?       printf("NUMBER: %s\n", yytext);
[ \t\r\n]+              ;
.                       printf("SYMBOL: %s\n", yytext);
%%

int main(void) { return yylex(); }
int yywrap(void) { return 1; }
