#include<stdio.h>

int main() {
    int choice;
    float x,y,res;
    char op[1];

    printf("Enter the numbers : <x> <y>\n");
    scanf("%f %f",&x,&y);

    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");

    getChoice: {
        printf("Enter the number corresponding to the operation you wish to perform: ");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                res = x + y;
                break;
            case 2:
                res = x - y;
                break;
            case 3:
                res = x * y;
                break;
            case 4:
                res = x / y;
                break;
            default:
                printf("%d is not a valid choice!\n",choice);
                goto getChoice;
        }
    }

    printf("Result : %f",res);
}