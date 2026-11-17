%{
#include<stdio.h>
int yylex();
void yyerror(char const*);
%}
%token TA TB
%%
list :
|list s '\n' {printf("\n Accepted...\n");return 1;}
;
s :TA
|s TB
;
%%
int main()
{
return(yyparse());
}
void yyerror(char const*s)
{
printf("%s\n",s);
}
int yylex()
{
int c;
while((c=getchar())==' ');
if(c=='a')return(TA);
if(c=='b')return(TB);
return(c);
}
int yywrap()
{
return(1);
}
