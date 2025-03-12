#include <stdio.h>

struct book {
    int ID, copies;
    float price;
    char bName[50], aName[25], pName[25]; 
};

int main() {
    int i, n;
    float tax;
    struct book Book[10];
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %s %s %s %d %f", &Book[i].ID, Book[i].bName, Book[i].aName, Book[i].pName, &Book[i].copies, &Book[i].price);
    }
    
    for (i = 0; i < n; i++) {
        if (Book[i].price > 500) {
            tax = 0.1 * Book[i].price;
        } else {
            tax = 0.05 * Book[i].price;
        }
        printf("%s %.2f\n", Book[i].bName, (Book[i].price + tax));
    }
}