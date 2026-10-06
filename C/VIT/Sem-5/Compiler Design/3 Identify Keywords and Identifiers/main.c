%{
#include &lt; stdio.h & gt;
%}
%%
int|float|char|if|else|while|for|return
{
  printf(&quot; KEYWORD : % s\n & quot;, yytext);
}
[a - zA - Z_][a - zA - Z0 - 9_] *
{ printf(&quot; IDENTIFIER : % s\n & quot;, yytext); }[0 - 9] +
{
  printf(&quot; NUMBER : % s\n & quot;, yytext);
}

[ \t\n];
.;
% % int yywrap() { return 1; }
int main() {
  printf(&quot; Enter C statement :\n & quot;);
  yylex();
  return 0;
}
