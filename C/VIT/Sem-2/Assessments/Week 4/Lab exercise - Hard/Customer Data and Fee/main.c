#include <stdio.h>

struct CustomerData {
    int customerID;
    double dataUsed, planLimit;
};

double calculateFee(double dataUsed, double planLimit) {
    if (dataUsed > planLimit) {
        return (dataUsed - planLimit) * 2.00;
    }
    return 0.0;
}

int main() {
    int n;
    scanf("%d", &n);
    struct CustomerData customers[n];
    double totalDataUsed = 0.0, totalPlanLimit = 0.0;
    int extraChargesExist = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %lf %lf", &customers[i].customerID, &customers[i].dataUsed, &customers[i].planLimit);
        totalDataUsed += customers[i].dataUsed;
        totalPlanLimit += customers[i].planLimit;
    }
    for(int i = 0; i < n; i++) {
        double fee = calculateFee(customers[i].dataUsed, customers[i].planLimit);
        if (fee > 0.0) {
            printf("%d %.2lf\n", customers[i].customerID,fee);
            extraChargesExist = 1;
        }
    }
    if (!extraChargesExist) {
        printf("No charges\n");
    }
    printf("Total Data Used: %.2lfGB\n", totalDataUsed);
    printf("Total Plan Limit: %.2lfGB\n", totalPlanLimit);
}