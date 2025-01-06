#include<stdio.h>

int main() {
	int arr[10],i,n,max;
	
	printf("Enter length of array: ");
	scanf("%d",&n);

	for(i=0;i<n;i++) {
		printf("Enter number %d: ",i+1);
		scanf("%d",&arr[i]);
	}

	max=arr[0];

	for(i=1;i<n;i++) {
		if(max<arr[i])
			max=arr[i];
	}

	printf("The maximum value is %d",max);
}