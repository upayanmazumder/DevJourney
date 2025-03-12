#include <stdio.h>
#include <string.h>

struct employee {
    int number;
    char name[50];
    int age;
    char designation[20];
    float basic_pay;
};

int main() {
    int i, n, j = 0, k = 0; 
    float da, hra, cca, pf, li, np;
    scanf("%d", &n);
    char rich[n][50];
    struct employee e[n];
    for (i = 0; i < n; i++) {
        scanf("%d %s %d %s %f", &e[i].number, e[i].name, &e[i].age, e[i].designation, &e[i].basic_pay);
    }
    
    for (i = 0; i < n; i++) {
        da = 0.5 * e[i].basic_pay;
        hra = 0.2 * e[i].basic_pay;
        cca = 0.1 * e[i].basic_pay;
        pf = 0.1 * e[i].basic_pay;
        li = 0.15 * e[i].basic_pay;
        np = da + hra + cca + pf + li + e[i].basic_pay;
        printf("%s allowance details:\n", e[i].name);
        printf("%.2f %.2f %.2f %.2f %.2f\n", da, hra, cca, pf, li);
        printf("Netpay: %.2f\n", np);
        if (np >= 50000) {
            strcpy(rich[j], e[i].name);
            j++;
        }
        if (e[i].age <= 30) {
            k++;
        }
    }
    printf("The following employees have netpay greater than 50000:\n");
    for (i = 0; i < j; i++) {
        printf("%s\n", rich[i]);
    }
    printf("Number of employees whose age <=30: %d", k);
}