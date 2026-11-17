%{
#include <stdio.h>
%}

%%

int|float|char|if|else|while|for|return    { printf("KEYWORD : %s\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]*                     { printf("IDENTIFIER : %s\n", yytext); }

[0-9]+                                     { printf("NUMBER : %s\n", yytext); }

[ \t\n]+                                   ;

.                                          ;

%%

int yywrap(void) {
    return 1;
}

int main(void) {
    printf("Enter C statement:\n");
    yylex();
    return 0;
}
