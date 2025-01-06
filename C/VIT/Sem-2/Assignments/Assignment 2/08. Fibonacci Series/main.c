#include<stdio.h>

int main() {
	int a, b, c, n = 1, count;
    printf("How many fibonacci numbers to print: ");
    scanf("%d",&count);
	
	for(a = 0;n <= count;n = n + 1)
		{
			switch(n)
				{
					case 1:
						b = 0;
						break;
					case 2:
						b = 1;
						a = 0;
						break;
					default:
						c = b;
						b = a + b;
						a = c;
						break;
				}
			printf("%d ",b);
		}
}


