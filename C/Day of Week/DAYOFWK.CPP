//Program to find the day of the week based on the number entered
#include<stdio.h>
#include<conio.h>
void main()
{
	int n,day;
	clrscr();
	printf("Enter the number correponding to the day : ");
	scanf("%d",&n);
	printf("The day of the week corresponding to %d is ",n);
	switch(n)
		{
			case 1:
				printf("Monday");
				break;
			case 2:
				printf("Tuesday");
				break;
			case 3:
				printf("Wednesday");
				break;
			case 4:
				printf("Thursday");
				break;
			case 5:
				printf("Friday");
				break;
			case 6:
				printf("Saturday");
				break;
			case 7:
				printf("Sunday");
				break;
		   }
	getch();
}