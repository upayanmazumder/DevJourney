%{
#include<stdio.h>
%}

%%

[0-9]+                  { printf("NUMBER : %s\n", yytext); }

[a-zA-Z]+               { printf("WORD   : %s\n", yytext); }

[ \t\n]+                ;

[^a-zA-Z0-9 \t\n]       { printf("SPECIAL CHARACTER : %s\n", yytext); }

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter text:\n");
    yylex();
    return 0;
}
