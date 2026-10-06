%{
#include&lt;stdio.h&gt;
int valid=1;
int yylex();
void yyerror(char *);
%}
%token A B
%%
str:S&#39;\n&#39; {return 0;}
S:A S B
|
;
%%
void yyerror (char const *s)
{
fprintf (stderr, &quot;%s\n&quot;, s); valid=0;
}
int yywrap()
{
return(1);
}
int main()
{
printf(&quot;Enter the string:\n&quot;);
yyparse();
if(valid==1)
printf(&quot;\nValid string&quot;);
return 0;
}
