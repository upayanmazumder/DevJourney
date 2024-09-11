//even nos in limit
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
	do
	{
	  if(i%2==0)
	   printf("%d ",i);
	   i=i+1;
	    }while(i<=h);
	getch();
    return 0;
}
