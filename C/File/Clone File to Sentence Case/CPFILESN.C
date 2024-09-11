//Programme to copy the content of a text file to another text file
//Result in sentence case
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
	FILE *P1,*P2;
	char ch,fsname[40],ftname[40];
	int flag=1;
	
	printf("Enter source file name : ");
	fgets(fsname, sizeof(fsname), stdin);
	printf("Enter target file name : ");
	fgets(ftname, sizeof(ftname), stdin);
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
			if(flag==1)
				{
					if(ch>=97  && ch<=122)
					ch-=32;
					flag=0;
				}
			else
				{
					if(ch>=65 && ch<=90)
						ch+=32;
				}
			putc(ch,P2);
			if(ch=='.')
				flag=1;
		}	while(ch!=EOF);
	printf("Source file has been copied into proper sentence case file!");
	fclose(P1);
	fclose(P2);
	getch();
    return 0;
}