//Program to input a sentence and count vowels, consonant,alphabets,
//digital character, special characters
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
int main()
{
	int v=0,c=0,a=0,d=0,s=0,i,ch,nxt;
	char snt[80];
	
	printf("Enter your sentence : ");
	scanf("%s",snt);
	for(i=0;snt[i]!='\0';i++)
		{
			if(nxt=='\n'==0)
				printf("SPACE");
			ch=toupper(snt[i]);
			if(ch>=48 && ch<=57)	//Digital characters
				d++;
			else if(ch>=65 && ch<=90)	//Alphabets
				{
					a++;
					//Vowels
					if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U') //Vowels
						v++;
					//Consonants
					else
						c++;
				}
			else 			//Special Characters
				{
					s++;
					nxt=snt[i+1];
					if(nxt==' ' || nxt==',' || nxt=='.' || nxt==';')
						{
							printf("\n!!! nxt character at %d is %c and current character at %d is %c",i+1,nxt,i,ch);
						}
				}
		}
	printf("\nAlphabets : %d\nVowels : %d\nConsonants : %d\nDigital characters : %d\nSpecial Characters : %d",a,v,c,d,s);
	getch();
    return 0;
}