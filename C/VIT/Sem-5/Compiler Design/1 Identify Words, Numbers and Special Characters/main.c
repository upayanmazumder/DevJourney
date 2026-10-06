%
        {
#include &lt; stdio.h & gt;
            % } %
        % [0 - 9] +
{
  printf(&quot; NUMBER : % s\n & quot;, yytext);
}
[a - zA - Z] + { printf(&quot; WORD : % s\n & quot;, yytext); }
[ \t\n] + ;
[^a - zA - Z0 - 9 \t\n] {
  printf(&quot; SPECIAL CHARACTER : % s\n & quot;, yytext);
} % %
    int yywrap() {
  return 1;
}
int main() {
  printf(&quot; Enter text :\n & quot;);
  yylex();
  return 0;
}
