#include <stdio.h>

struct DEP_STORE {
    char store_name[50], store_address[100];
    long int phone_no;
};

struct STORE_ITEM {
    int item_number, available_qty;
    float item_price;
    char item_name[50];
};

int main() {
    struct DEP_STORE s;
    fgets(s.store_name, sizeof(s.store_name),stdin);
    fgets(s.store_address, sizeof(s.store_address), stdin);
    scanf("%ld", &s.phone_no);
    int i, j, N;
    float tot = 0;
    scanf("%d", &N);
    struct STORE_ITEM item[N];
    for(i = 0; i < N; i++) {
        scanf("%d", &item[i].item_number);
        while (getchar() != '\n');
        fgets(item[i].item_name, sizeof(item[i].item_name), stdin);
        scanf("%d %f", &item[i].available_qty, &item[i].item_price);
    }
    
    printf("Store Name: %s", s.store_name);
    printf("Store Address: %s", s.store_address);
    printf("Phone Number: %ld\n", s.phone_no);
    
    printf("\nItem Number\t Item Name\tAvailable Quantity\tItem Price\n");
    for(i = 0; i < N; i++) {
        printf("%d\t", item[i].item_number);
        //printf("%s", item[i].item_name);
        j = 0;
        while (item[i].item_name[j] != '\n') {
            printf("%c", item[i].item_name[j]);
            j++;
        }
        printf("%d\t", item[i].available_qty);
        printf("%.2f\n", item[i].item_price);
        tot += item[i].available_qty * item[i].item_price;
    }
    printf("Total Item Value: Rs. %.2f", tot);
}