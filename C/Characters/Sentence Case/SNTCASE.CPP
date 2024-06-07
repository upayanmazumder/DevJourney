//Proram to convert a sentence in lowercase to uppercase
#include<stdio.h>
#include<conio.h>
void main()
{
	char str[20];
	int i;
	clrscr();
	printf("Enter your string\n> ");
	scanf("%s",str);
	if(str[0]<=122 & str[0]>=97)
		str[0]=str[0]-32;
	printf(">> %s",str);
	getch();
}