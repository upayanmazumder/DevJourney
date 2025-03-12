#include <stdio.h>

struct Customer {
    char name[50];
    int number;
    float balance;
};

void printCustomersWithLowBalance(struct Customer customer[], int n) {
    int i;
    bool found = false;
    for (i = 0; i < n; i++) {
        if (customer[i].balance < 200)  {
            printf("%s\n", customer[i].name);
            found = true;
        }
    }
    if (!found) {
        printf("None\n");
    }
}

void addBalanceForHighBalanceCustomers(struct Customer customer[], int n) {
    int i;
    bool found = false;
    for (i = 0; i < n; i++) {
        if (customer[i].balance > 1000) {
            customer[i].balance += 100;
            printf("%s Rs.%.2f\n", customer[i].name,customer[i].balance);
            found = true;
        }
    }
    if (!found) {
        printf("None\n");
    }
}

int main() {
    int i, n;
    struct Customer customer[15];
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s %d %f", customer[i].name, &customer[i].number, &customer[i].balance);
    }
    
    printf("Customers: ");
    printCustomersWithLowBalance(customer, n);
    printf("Incremented balance: ");
    addBalanceForHighBalanceCustomers(customer, n);
}