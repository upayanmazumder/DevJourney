#include<stdio.h>
#include<conio.h>
#include<ctype.h>
int main()
{
	char name[80];
	int i,j;
	
	printf("Enter full name : ");
	fgets(name, sizeof(name), stdin);
	printf("The output is  : ");
	printf("%c",toupper(name[0]));
	for(i=1;name[i]!='\0';i++)
		{
			if(name[i]==' ')
				printf(".%c",toupper(name[i+1]));
		}
	for(i=i-1;i>=0;i--)
		if(name[i]==' ')
		break;
	for(i=i+2;name[i]!='\0';i++)
		printf("%c",tolower(name[i]));
	getch();
    return 0;
}