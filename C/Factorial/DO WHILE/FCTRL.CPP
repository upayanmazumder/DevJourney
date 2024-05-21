#include<stdio.h>
#include<conio.h>
void main()
{
	int i=1,n,f=1;
	clrscr();
	printf("Enter a number : ");
	scanf("%d",&n);
	do {
		f=f*i;
		i++;
	   }	while(i<=n);
	printf("The factorial of %d is ",n);
	printf("%d",f);
	getch();
}