#include<stdio.h>
#include<conio.h>
int main() 
{
	int i,l,h;
	
	printf("Enter upper limit : ");
	scanf("%d",&h);
	printf("Enter lower limit : ");
	scanf("%d",&l);
	i=l;
	do {
		if(i%2!=0) //i is odd
		printf("%d ",i);
		i++;
	   } while(i<=h);
	getch();
    return 0;
}