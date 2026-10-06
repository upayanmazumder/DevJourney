%
        {
#include &lt; stdio.h & gt;
            % } %
        % [0 - 9] +
    &quot;
.&quot;
[0 - 9] + { printf(&quot; FLOAT : % s\n & quot;, yytext); }
[0 - 9] + { printf(&quot; INTEGER : % s\n & quot;, yytext); }
[a - zA - Z] + { printf(&quot; WORD : % s\n & quot;, yytext); }
[ \t\n] + ;
.;
% % int yywrap() { return 1; }
int main() {
  yylex();
  return 0;
}
