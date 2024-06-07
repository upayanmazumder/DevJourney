//Proram to convert a string in lowercase to uppercase
#include<stdio.h>
#include<conio.h>
void main()
{
	char str[20];
	int i;
	clrscr();
	printf("Enter your string \n> ");
	scanf("%s",str);
	for(i=0;str[i]!='\0';i++)
		{
			if(str[i]>=65 && str[i]<=90)
			str[i]=str[i]+32;
		}
	printf(">> %s",str);
	getch();
}