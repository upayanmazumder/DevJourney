%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

int yylex()
{
    int c;

    /* Ignore spaces and tabs */
    while ((c = getchar()) == ' ' || c == '\t')
        ;

    /* Number */
    if (isdigit(c) || c == '.') {
        double value = 0;
        double fraction = 0.1;

        /* Integer part */
        while (isdigit(c)) {
            value = value * 10 + (c - '0');
            c = getchar();
        }

        /* Decimal part */
        if (c == '.') {
            c = getchar();

            while (isdigit(c)) {
                value += (c - '0') * fraction;
                fraction *= 0.1;
                c = getchar();
            }
        }

        yylval = value;
        ungetc(c, stdin);

        return NUMBER;
    }

    return c;
}

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
