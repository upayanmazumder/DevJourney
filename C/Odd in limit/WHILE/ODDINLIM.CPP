//program to input higher and lower limit and print odd numbers in it
#include<stdio.h>
#include<conio.h>
void main()
{
	int l,h,i;
	clrscr();
	printf("Enter upper limit : ");
	scanf("%d",&h);
	printf("Enter lower limit : ");
	scanf("%d",&l);
	i=l;
	while(i%2==0)
		{
			i=i+1;
		}
	while(i<=h)
		{
			printf("%d ",i);
			i=i+2;
		}
	getch();
}