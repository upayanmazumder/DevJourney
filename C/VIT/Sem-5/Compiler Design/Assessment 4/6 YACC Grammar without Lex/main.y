%{
#include <stdio.h>
#include <ctype.h>
int yylex(void);
void yyerror(const char *s);
%}
%token A B INVALID
%%
input: S '\n' { puts("Valid string"); } | S { puts("Valid string"); };
S: A S B | ;
%%
int yylex(void) {
  int c;
  do c = getchar(); while (c == ' ' || c == '\t' || c == '\r');
  if (c == 'a') return A;
  if (c == 'b') return B;
  if (c == EOF || c == '\n') return c;
  return INVALID;
}
void yyerror(const char *s) { (void)s; puts("Invalid string"); }
int main(void) { return yyparse(); }
