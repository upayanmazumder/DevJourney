% {
#include &lt; stdio.h & gt;
  int word = 0, digit = 0, special = 0;
  %
}
% %

        [a - zA - Z] +
{
  word++;
}
[0 - 9] + { digit++; }
[ \t\n] + ;
[^a - zA - Z0 - 9 \t\n] { special++; } % % int yywrap() { return 1; }
int main() {
  printf(&quot; Enter text :\n & quot;);
  yylex();
  printf(&quot;\nWords = % d & quot;, word);
  printf(&quot;\nNumbers = % d & quot;, digit);
  printf(&quot;\nSpecial Characters = % d\n & quot;, special);
  return 0;
}
