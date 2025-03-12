#include <stdio.h>
#include <string.h>
#define MAX_PRODUCT 100

struct Product {
    int product_number, num_items;
    float cost_per_product;
    char expiry_date[11];
};

void displayByProductNumber(struct Product products[], int n, int search_product_number) {
    for (int i = 0; i < n; i++) {
        if (products[i].product_number == search_product_number) {
            printf("Product details of the searched product number\n %d %.2f %d %s\n", products[i].product_number, products[i].cost_per_product, products[i].num_items, products[i].expiry_date);
            return;
        }
    }
}

void displayAboveCost(struct Product products[], int n, float search_cost) {
    for (int i = 0; i < n; i++) {
        if (products[i].cost_per_product == search_cost) {
            printf("\nProduct details of the searched product cost\n %d %.2f %d %s\n", products[i].product_number, products[i].cost_per_product, products[i].num_items, products[i].expiry_date);
            return;
        }
    }
}

void displayByExpiryDate(struct Product products[], int n, char search_expiry_date[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(products[i].expiry_date, search_expiry_date) == 0) {
            printf("\nProduct with the searched expiry date\n %d %.2f %d %s\n", products[i].product_number, products[i].cost_per_product, products[i].num_items, products[i].expiry_date);
            return;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    struct Product products[MAX_PRODUCT];
    for (int i = 0; i < n; i++) {
        scanf("%d %f %d %s", &products[i].product_number, &products[i].cost_per_product, &products[i].num_items, products[i].expiry_date);
    }
    int search_product_number;
    float search_cost;
    char search_expiry_date[11];
    scanf("%d", &search_product_number);
    scanf("%f", &search_cost);
    scanf("%s", search_expiry_date);
    displayByProductNumber(products, n, search_product_number);
    displayAboveCost(products, n, search_cost);
    displayByExpiryDate(products, n, search_expiry_date);
}