%{
#include&lt;stdio.h&gt;
int yylex();
void yyerror(char const*);
%}
%token TA TB
%%
list :
|list s &#39;\n&#39; {printf(&quot;\n Accepted...\n&quot;);return 1;}
;
s :TA s
|TB
;
%%
int main()
{
return(yyparse());
}
void yyerror(char const*s)
{
printf(&quot;%s\n&quot;,s);
}
int yylex()
{
int c;
while((c=getchar())==&#39; &#39;);
if(c==&#39;a&#39;)return(TA);
if(c==&#39;b&#39;)return(TB);
return(c);
}
int yywrap()
{
return(1);
}
