//Programme to copy the content of a text file to another text file
//Result in toggle case
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main() 
{
	FILE *P1,*P2;
	char ch,fsname[40],ftname[40];
	int flag=1;
	
	printf("Enter source file name : ");
	gets(fsname);
	printf("Enter target file name : ");
	gets(ftname);
	P1=fopen(fsname,"r");
	P2=fopen(ftname,"w");
	if(P1==NULL || P2==NULL)
		{
			printf("Source/Target file could not be found");
			getch();
			exit(0);
		}
	do
		{
			ch=getc(P1);
			if(ch>=97  && ch<=122) //Convert low to up
				ch-=32;
			else if(ch>=65 && ch<=90) //Convert up to low
				ch+=32;
			putc(ch,P2);
		}	while(ch!=EOF);
	printf("Source file has been copied into proper toggle case file!");
	fclose(P1);
	fclose(P2);
	getch();
    return 0;
}