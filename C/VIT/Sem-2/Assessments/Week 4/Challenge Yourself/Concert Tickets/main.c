#include <stdio.h>
#define BASE_TICKET_PRICE 900.00
#define STUDENT_DISCOUNT 0.05
#define GROUP_DISCOUNT 0.10

struct Visit {
    int member_count, student_status;
};

struct Loyal {
    double student_discount, group_discount;
};

double calculateTotalCost(struct Visit visit, struct Loyal loyal) {
    double discounted_price = BASE_TICKET_PRICE;
    if (visit.student_status == 1) {
        discounted_price *= (1 - loyal.student_discount);
    }
    if (visit.member_count > 5) {
        discounted_price *= (1 - loyal.group_discount);
    }
    return visit.member_count * discounted_price;
}

int main() {
    struct Visit visit;
    struct Loyal loyal = {STUDENT_DISCOUNT, GROUP_DISCOUNT};
    scanf("%d", &visit.member_count);
    scanf("%d", &visit.student_status);
    double total_cost = calculateTotalCost(visit, loyal);
    printf("Rs. %.2f\n", total_cost);
}