#include <stdio.h>

struct Student {
    int id;
    char name[50];
};

void modify(struct Student *s) {
    s->id = 999; // Modifying value
}

int main() {
    struct Student s1 = {101, "Upayan"};
    modify(&s1);
    printf("Updated ID: %d\n", s1.id);
    return 0;
}
