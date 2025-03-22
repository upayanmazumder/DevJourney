#include <stdio.h>

struct Student {
    int id;
    char name[50];
};

void display(struct Student s) {
    printf("ID: %d, Name: %s\n", s.id, s.name);
}

int main() {
    struct Student s1 = {101, "Upayan"};
    display(s1);
    return 0;
}
