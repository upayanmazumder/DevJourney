#include <stdio.h>

struct details {
    char name[100];
    int number;
    int quantity;
    int price;
};

int main() {
    int i, N;
    struct details item[25];
        
    scanf("%d", &N);
    
    for(i = 0; i < N; i++) {
        scanf("%s %d %d %d", &item[i].name, &item[i].number, &item[i].quantity, &item[i].price);
    }
    
    for (i = 0; i < N; i++) {
        printf("%s %d\n",item[i].name,item[i].price * item[i].quantity);
    }
}