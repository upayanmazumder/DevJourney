%{
#include &quot;y.tab.h&quot;
%}
%%
a return A;
b return B;
.|\n return yytext[0];
%%
