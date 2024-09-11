//Binary Search Program
#include<stdio.h>
#include<conio.h>
int main()
{
	int a[10],i,n,b[10],j=0;
	
	printf("<<< ARRAY >>>\n");
	for(i=0;i<10;i++)
		{
			printf("Number %d : ",i+1);
			scanf("%d",&a[i]);
		}
	printf("<<< SEARCH >>>\n");
	printf("Enter the number to look for in the array : ");
	scanf("%d",&n);
	for(i=0;i<10;i++) //For every term in the user input
		{
			if(a[i]==n)  //If the term's value is a match
				{
					b[j]=i; //Add the position to the out array
					j++; //Adjust position of out array
				}
		}
	if(j>0) 	//If at least one match is found
		{
			printf("The number %d is present at the ",n);
			if(j==1) //Only one match is found
				printf("position ");
			else //Multiple matches are found
				printf("positions ");
			for(i=0;i<j;i++)  //Print the positions
				printf("%d ",b[i]);
			printf("of the array");
		}
	else
		{
			printf("The number %d is not present in the array!",n);
		}
	getch();
    return 0;
}