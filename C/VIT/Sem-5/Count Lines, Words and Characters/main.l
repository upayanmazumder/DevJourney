%{
#include<stdio.h>

int lines=0,words=0,chars=0;
%}

%%

\n              { lines++; chars++; }

[ \t]+          { chars+=yyleng; }

[a-zA-Z0-9]+
{
words++;
chars+=yyleng;
}

.               { chars++; }

%%

int yywrap()
{
return 1;
}

int main()
{
printf("Enter text (Ctrl+Z then Enter to stop):\n");
yylex();

printf("Lines = %d\n",lines);
printf("Words = %d\n",words);
printf("Characters = %d\n",chars);

return 0;
}
