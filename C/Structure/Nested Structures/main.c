struct Address {
    char city[50];
    int pin;
};

struct Student {
    int id;
    struct Address addr; // Nested structure
};

int main() {
    struct Student s1 = {101, {"Kolkata", 700001}};

    printf("ID: %d\n", s1.id);
    printf("City: %s\n", s1.addr.city);
    printf("Pincode: %d\n", s1.addr.pin);

    return 0;
}
