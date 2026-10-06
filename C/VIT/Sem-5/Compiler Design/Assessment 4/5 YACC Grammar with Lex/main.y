%{
#include <stdio.h>
int yylex(void);
void yyerror(const char *s);
%}
%token A B
%%
input: S '\n' { puts("Valid string"); } | S { puts("Valid string"); };
S: A S B | ;
%%
void yyerror(const char *s) { (void)s; puts("Invalid string"); }
int main(void) { return yyparse(); }
