//Programme to copy the content of a text file to another text file
//Result in lowercase
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
	FILE *P1,*P2;
	char ch,fsname[40],ftname[40];
	
	printf("Enter your source file name : ");
	scanf("%s",fsname);
	fflush(stdin);
	printf("Enter your new file name : ");
	scanf("%s",ftname);
	P1=fopen(fsname,"r");
	P2=fopen(ftname,"w");
	if(P1==NULL || P2==NULL)
		{
			printf("Source/Target file cannot be opened!");
			getch();
			exit(0);
		}
	do
		{
			ch=tolower(getc(P1));
			putc(ch,P2);
		}
	while(ch!=EOF);
	printf("Source file copied.....");
	fclose(P1);
	fclose(P2);
	getch();
    return 0;
}