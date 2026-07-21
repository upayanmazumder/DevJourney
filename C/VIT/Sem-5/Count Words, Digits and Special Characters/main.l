%{
#include<stdio.h>

int word=0,digit=0,special=0;
%}

%%

[a-zA-Z]+       { word++; }

[0-9]+          { digit++; }

[ \t\n]+        ;

[^a-zA-Z0-9 \t\n]   { special++; }

%%

int yywrap()
{
return 1;
}

int main()
{
printf("Enter text:\n");
yylex();

printf("\nWords = %d",word);
printf("\nNumbers = %d",digit);
printf("\nSpecial Characters = %d\n",special);

return 0;
}
