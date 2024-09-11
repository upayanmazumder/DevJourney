//Program to check whether an alphabet is a vowel or a consonant
#include<stdio.h>
#include<conio.h>
int main() 
{
	char i;
	
	printf("Enter the alphabet you wish to check : ");
	scanf("%c",&i);
	printf("The letter you have provided, '%c', is a ",i);
	switch(i)
		{
			case 'a':case 'A':
			case 'e':case 'E':
			case 'i':case 'I':
			case 'o':case 'O':
			case 'u':case 'U':
				printf("vowel.");break;
			default:
				printf("consonant.");break;
		}
	getch();
    return 0;
}