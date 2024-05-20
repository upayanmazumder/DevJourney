//Multiplication table
#include<stdio.h>
#include<conio.h>
void main()
{
	int n,p,i;
	clrscr();
	printf("Enter a number : ");
	scanf("%d",&n);
	i=1;
	printf("MULTIPLICATION TABLE OF %d",n);
	while(i<=10)
		{
			p=i*n;
			printf("\n%d x ",n);
			printf("%d = ",i);
			printf("%d",p);
			i=i+1;
		}
	getch();
}