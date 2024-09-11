//Program to print prime and composite numbers of an array
#include<stdio.h>
#include<conio.h>
int main()
{
	int arr[10],i,n,d,c;
	
	printf("Enter length of array: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		{
			printf("Enter number %d : ",i+1);
			scanf("%d",&arr[i]);
		}
	for(i=0;i<n;i++)	//for each term of array from i=0 to last
		{
			c=0; //reset factor count
			for(d=2;d<arr[i];d++)	//assign p&c divisor to term
				{
					if(arr[i]%d==0)	//d is factor of term
						c=c++;  //adjust factor count
				}
			if(c>0)	//Term has a factor
				printf("%d is composite\n",arr[i]);
			else if(arr[i]==2)
				printf("2 is composite\n");
			else	//Term is prime
				printf("%d is prime\n",arr[i]);

		}
	getch();
    return 0;
}