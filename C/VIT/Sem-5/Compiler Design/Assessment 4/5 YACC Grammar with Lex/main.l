%{
#include "y.tab.h"
%}
%%
a       return A;
b       return B;
[ \t\r]+ ;
\n      return '\n';
.       return yytext[0];
%%
int yywrap(void) { return 1; }
