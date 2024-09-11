//Program to input higher and lower limit and get all even numbers in range
#include<stdio.h>
#include<conio.h>
int main()
{
	int l,h,i;
	
	printf("Enter upper limit : ");
	scanf("%d",&h);
	printf("Enter lower limit : ");
	scanf("%d",&l);
	i=l;
	while((i%2)!=0)
		{
			i=i+1;
		}
	while(i<=h)
		{
		 printf("%d ",i);
		 i=i+2;
		}
	getch();
    return 0;
}