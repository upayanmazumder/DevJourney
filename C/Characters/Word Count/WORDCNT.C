//Proram to count number of words in a sentence
#include<stdio.h>
#include<conio.h>
int main() 
{
	char ren[80],ch;
	int i,c=0;
	
	printf("Enter your sentence : ");
	fgets(ren, sizeof(ren), stdin);
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
    return 0;
}