//Proram to convert a sentence in lowercase to uppercase
#include<stdio.h>
#include<conio.h>
int main()
{
	char str[20];
	int i;
	
	printf("Enter your string\n> ");
	scanf("%s",str);
	if(str[0]<=122 & str[0]>=97)
		str[0]=str[0]-32;
	printf(">> %s",str);
	getch();
    return 0;
}