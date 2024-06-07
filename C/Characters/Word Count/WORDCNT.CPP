//Proram to count number of words in a sentence
#include<stdio.h>
#include<conio.h>
void main()

{
	char ren[80],ch;
	int i,c=0;
	clrscr();
	printf("Enter your sentence : ");
	gets(ren);
	for(i=0;ren[i]!='\0';i++)
		{
			if(ren[i]==' ' || ren[i]==',' || ren[i]=='.' || ren[i]==';')
				{
					c++;
					while(ren[i+1]==' ' || ren[i+1]==',' || ren[i+1]=='.' || ren[i+1]==';')
						i++;
				}
		}
	c++;
	printf("\n The number of words in the sentence is %d",c);
	getch();
}