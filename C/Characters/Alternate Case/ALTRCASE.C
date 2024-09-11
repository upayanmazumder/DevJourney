//Proram to convert lowercase to uppercase and vice versa
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
			if(str[i]>=65 && str[i]<=90)
			str[i]=str[i]+32;
			else
			str[i]=str[i]-32;
		}
	printf(">> %s",str);
	getch();
    return 0;
}