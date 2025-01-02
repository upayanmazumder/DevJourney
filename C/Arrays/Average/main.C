#include<stdio.h>

int main() {
	int arr[10],i,n,s=0,avg;
	
	printf("How many numbers: ");
	scanf("%d",&n);

	for(i=0;i<n;i++) {
		printf("Enter number %d: ",i+1);
		scanf("%d",&arr[i]);
	}

	for(i=0;i<n;i++) {
		s+=arr[i];
	}

	avg=s/n;
	printf("Average of the elements of the array is %d",avg);
}