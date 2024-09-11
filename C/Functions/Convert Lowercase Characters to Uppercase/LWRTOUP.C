//Proram to convert a string in lowercase to uppercase
#include<stdio.h>
#include<conio.h>
int main() 
{
	char str[20];
	int i;
	
	printf("Enter your string \n> ");
	scanf("%s",str);
	for(i=0;str[i]!='\0';i++)
		{
			if(str[i]>=97 && str[i]<=122)
			str[i]=str[i]-32;
		}
	printf(">> %s",str);
	getch();
    return 0;
}