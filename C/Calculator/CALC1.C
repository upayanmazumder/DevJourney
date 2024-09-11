//Calculator using "if" statement
#include<stdio.h>
#include<conio.h>
int main()
{
	int n1,n2,op,val,res;
	//The op variable is used for the operation
	//The val variable indicates validity by 0 (false) and 1 (true)
	//The res variable is used for the result
	
	printf("Enter the first number : ");
	scanf("%d",&n1);
	printf("Enter the second number : ");
	scanf("%d",&n2);
	printf("(1) Addition \n(2) Subtraction \n(3) Multiplication\n(4) Divison");
	printf("\nPlease enter the number corresponding to the operation you wish to perform : ");
	scanf("%d",&op);
	val=1; //We assume that the operation is valid
	if(op==1)          //For valid operations, val remain 1
		res=n1+n2;
	else if(op==2)     //Valid operation
		res=n1-n2;
	else if(op==3)     //Valid operation
		res=n1*n2;
	else if(op==4)     //Valid operation
		res=n1/n2;
	else
		val=0; //For invalid operations, val is changed to 0
	if(val==0) //Handler for invalid operation
		printf("You have entered an invalid number for operation!!!");
	else //Handler for valid operation
		printf("Result = %d",res);
	getch();
    return 0;
}