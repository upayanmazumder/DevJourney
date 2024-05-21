#include<stdio.h>
#include<conio.h>
void main()
{
	int i=1,n,p;
	clrscr();
	printf("Enter a number: ");
	scanf("%d",&n);
	do {
		printf("\n%d x ",n);
		printf("%d = ",i);
		p=i*n;
		printf("%d",p);
		i++;
	   } while(i<=10);
	getch();
}
