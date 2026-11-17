%{
#include <stdio.h>
int vowel = 0, consonant = 0;
%}
%%
[aAeEiIoOuU]                 { vowel++; }
[a-zA-Z]                     { consonant++; }
.|\n                          ;
%%
int yywrap(void) {
    return 1;
}
int main(void) {
    printf("Enter text:\n");
    yylex();
    printf("Vowels = %d\n", vowel);
    printf("Consonants = %d\n", consonant);
    return 0;
}
