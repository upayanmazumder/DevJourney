#include <stdio.h>

struct Address {
    int doorNo;
    char street[100];
    char city[100];
    int pincode;
};

struct Employee {
    char name[100];
    int id, age;
    char gender;
    struct Address addr;
    float bp, da, hra;
};

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    getchar();

    struct Employee e[n];

    for (int i = 0; i < n; ++i) {
        printf("\nEmployee %d ==>\n", i + 1);

        printf("\tName: ");
        fgets(e[i].name, sizeof(e[i].name), stdin);

        printf("\tID: ");
        scanf("%d", &e[i].id);

        printf("\tAge: ");
        scanf("%d", &e[i].age);

        printf("\tGender: ");
        scanf(" %c", &e[i].gender);

        printf("\tAddress ->\n");

        printf("\t\tDoor number: ");
        scanf("%d", &e[i].addr.doorNo);
        getchar();

        printf("\t\tStreet: ");
        fgets(e[i].addr.street, sizeof(e[i].addr.street), stdin);

        printf("\t\tCity: ");
        fgets(e[i].addr.city, sizeof(e[i].addr.city), stdin);

        printf("\t\tPincode: ");
        scanf("%d", &e[i].addr.pincode);

        printf("\tSalary ->\n");

        printf("\t\tBasic Pay: ");
        scanf("%f", &e[i].bp);

        printf("\t\tDearness Allowance: ");
        scanf("%f", &e[i].da);

        printf("\t\tHouse Rent Allowance: ");
        scanf("%f", &e[i].hra);
        getchar();
    }

    for (int i = 0; i < n; ++i) {
        float total = e[i].bp + (e[i].bp * e[i].da / 100) + (e[i].bp * e[i].hra / 100);

        printf("\nDetails of Employee %d:\n", i + 1);
        printf("\tName: %s", e[i].name);
        printf("\tID: %d\n", e[i].id);
        printf("\tAge: %d\n", e[i].age);
        printf("\tGender: %c\n", e[i].gender);

        printf("\tAddress:\n");
        printf("\t\tDoor No: %d\n", e[i].addr.doorNo);
        printf("\t\tStreet: %s", e[i].addr.street);
        printf("\t\tCity: %s", e[i].addr.city);
        printf("\t\tPincode: %d\n", e[i].addr.pincode);

        printf("\tTotal Salary: %.2f\n", total);
    }

    return 0;
}
