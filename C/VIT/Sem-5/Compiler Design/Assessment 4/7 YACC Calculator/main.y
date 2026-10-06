%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int yylex(void);
void yyerror(const char *s);
%}
%union { double value; }
%token <value> NUMBER
%type <value> expr
%left '+' '-'
%left '*' '/'
%right UMINUS
%%
input: %empty | input expr '\n' { printf("%.6g\n", $2); };
expr: NUMBER { $$ = $1; }
    | expr '+' expr { $$ = $1 + $3; }
    | expr '-' expr { $$ = $1 - $3; }
    | expr '*' expr { $$ = $1 * $3; }
    | expr '/' expr { if ($3 == 0) { yyerror("division by zero"); YYERROR; } $$ = $1 / $3; }
    | '-' expr %prec UMINUS { $$ = -$2; }
    | '(' expr ')' { $$ = $2; };
%%
int yylex(void) {
  int c;
  do c = getchar(); while (c == ' ' || c == '\t' || c == '\r');
  if (isdigit(c) || c == '.') {
    char text[128]; int n = 0;
    do { if (n < 127) text[n++] = (char)c; c = getchar(); } while (isdigit(c) || c == '.');
    text[n] = '\0'; if (c != EOF) ungetc(c, stdin);
    yylval.value = strtod(text, NULL); return NUMBER;
  }
  return c;
}
void yyerror(const char *s) { fprintf(stderr, "Error: %s\n", s); }
int main(void) { return yyparse(); }
