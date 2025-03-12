#include <stdio.h>
#include <string.h>

struct Patient {
    int id, gender, age;
    char name[50];
};

void print_gender(struct Patient patients[], int n) {
    int male_count = 0, female_count = 0;
    for (int i = 0; i < n; i++) {
        if (patients[i].gender == 1)
            male_count++;
        else if (patients[i].gender == 2)
            female_count++;
    }
    printf("Count: %d %d\n", male_count, female_count);
}

void print_age(struct Patient patients[], int n) {
    int flag = 0;
    printf("Above 40: ");
    for (int i = 0; i < n; i++) {
        if (patients[i].age > 40) {
            printf(" %s", patients[i].name);
            flag = 1;
        }
    }
    if (flag == 0) {
        printf(" 0");
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    struct Patient patients[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %s %d %d", &patients[i].id, &patients[i].name, &patients[i].gender, &patients[i].age);
    }
    print_gender(patients, n);
    print_age(patients, n);
    return 0;
}