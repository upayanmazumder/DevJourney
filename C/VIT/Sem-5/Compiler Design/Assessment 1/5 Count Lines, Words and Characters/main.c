% {
#include &lt; stdio.h & gt;
  int lines = 0, words = 0, chars = 0;
  %
}
% %
\n {
  lines++;
  chars++;
}
[ \t] + { chars += yyleng; }
[a - zA - Z0 - 9] + {
  words++;
  chars += yyleng;
}
.{ chars++; }
% % int yywrap() { return 1; }
int main() {
  printf(&quot; Enter text(Ctrl + Z then Enter to stop) :\n & quot;);
  yylex();
  printf(&quot; Lines = % d\n & quot;, lines);
  printf(&quot; Words = % d\n & quot;, words);

  printf(&quot; Characters = % d\n & quot;, chars);
  return 0;
}
