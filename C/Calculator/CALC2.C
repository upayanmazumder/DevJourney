//Calculator using "switch"
#include<stdio.h>
#include<conio.h>
int main()
{
	int ch;
	float n1,n2,res;
	
	printf("Enter number 1 : ");
	scanf("%f",&n1);
	printf("Enter number 2 : ");
	scanf("%f",&n2);
	printf("Please enter the number corresponding to the \noperation you wish to perform : ");
	printf("\n (1) Addition\n (2) Subtraction\n (3) Multiplication\n (4) Division ");
	scanf("%d",&ch);
	printf("Result : ");
	switch(ch)
		{
			case 1:
				res=n1+n2;
				printf("%f",res);
				break;
			case 2:
				res=n1-n2;
				printf("%f",res);
				break;
			case 3:
				res=n1*n2;
				printf("%f",res);
				break;
			case 4:
				res=n1/n2;
				printf("%f",res);
				break;
			default:
				printf("INVALID!!! Please check your input!!!");
				break;
		}
	getch();
    return 0;
}