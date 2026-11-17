%{
#include<stdio.h>
int valid=1;
int yylex();
void yyerror(char const *);
%}
%token A B
%%
str:S'\n' {return 0;}
S:A S B
|
;
%%
void yyerror (char const *s)
{
fprintf (stderr, "%s\n", s); valid=0;
}
int yywrap()
{
return(1);
}
int main()
{
printf("Enter the string:\n");
yyparse();
if(valid==1)
printf("\nValid string");
return 0;
}
