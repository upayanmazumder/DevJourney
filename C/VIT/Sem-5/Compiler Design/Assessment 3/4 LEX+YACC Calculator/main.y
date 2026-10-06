%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s);
%}

%token NUMBER

%left '+' '-'
%left '*' '/'
%right UMINUS

%%

input:
      /* empty */
    | input line
    ;

line:
      '\n'
    | expr '\n'    {
                      printf("Result = %.2f\n", $1);
                   }
    ;

expr:
      NUMBER          { $$ = $1; }
    | expr '+' expr   { $$ = $1 + $3; }
    | expr '-' expr   { $$ = $1 - $3; }
    | expr '*' expr   { $$ = $1 * $3; }
    | expr '/' expr   {
                          if ($3 == 0) {
                              printf("Error: Division by zero\n");
                              $$ = 0;
                          }
                          else
                              $$ = $1 / $3;
                       }
    | '(' expr ')'    { $$ = $2; }
    | '-' expr %prec UMINUS
                      { $$ = -$2; }
    ;

%%

void yyerror(const char *s)
{
    printf("Invalid expression\n");
}

int main()
{
    printf("Simple Calculator\n");
    printf("Enter expression (Ctrl+D to exit):\n");
    yyparse();
    return 0;
}
