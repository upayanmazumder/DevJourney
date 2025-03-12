#include <stdio.h>

struct Customer {
    char name[50];
    int number;
    float balance;
};

int main() {
    int i, N;
    scanf("%d", &N);
    struct Customer customer[N];
    
    for (i = 0; i < N; i++) {
        scanf("%s %d %f", customer[i].name, &customer[i].number, &customer[i].balance);
    }
    
    printf("Customers with balance less than Rs.200:\n");
    for (i = 0; i < N; i ++) {
        if (customer[i].balance < 200) {
            printf("%s ", customer[i].name);
        }
    }
    
    for (i = 0; i < N; i++) {
        if (customer[i].balance > 1000) {
            customer[i].balance = 1.03 * customer[i].balance;
            printf("\nUpdated balance of %s: Rs. %.2f", customer[i].name, customer[i].balance);
        }
    }
}