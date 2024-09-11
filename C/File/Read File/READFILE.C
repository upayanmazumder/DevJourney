//Program to display the content of a text file
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main() 
{
	char ch;
	FILE *P;
	char fname[20];
	
	printf("Enter your file name : ");
	scanf("%s",fname);
	P=fopen(fname,"r");
	if(P==NULL)
		{
			printf("The file could not be opened!");
			getch();
			exit(0);
		}
	ch=getc(P);
	while(ch!=EOF)
		{
			printf("%c",ch);
			ch=getc(P);
		}
	getch();
	fclose(P);
    return 0;
}