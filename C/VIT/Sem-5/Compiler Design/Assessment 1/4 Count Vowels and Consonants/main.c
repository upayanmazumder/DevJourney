% {
#include &lt; stdio.h & gt;
  int vowel = 0, consonant = 0;
  %
}
% % [aAeEiIoOuU] { vowel++; }[a - zA - Z] { consonant++; }
.|\n;
% % int yywrap() { return 1; }
int main() {
  printf(&quot; Enter text :\n & quot;);
  yylex();
  printf(&quot; Vowels = % d\n & quot;, vowel);
  printf(&quot; Consonants = % d\n & quot;, consonant);
  return 0;
}
