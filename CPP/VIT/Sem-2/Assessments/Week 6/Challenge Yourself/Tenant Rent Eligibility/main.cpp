#include <iostream>
#include <iomanip>
using namespace std;

class Tenant {
protected:
    double monthlyIncome;

public:
    Tenant(double income) : monthlyIncome(income) {}
};

class RentEligibility : public Tenant {
    double rentPercentage;

public:
    RentEligibility(double income, double percentage) : Tenant(income), rentPercentage(percentage) {}

    void checkEligibility() {
        if (monthlyIncome >= 15000.0) {
            cout << "Eligible" << endl;
            double rentAmount = (rentPercentage / 100) * monthlyIncome;
            cout << "Rent Amount: " << fixed << setprecision(2) << rentAmount << endl;
        } else {
            cout << "Not Eligible" << endl;
        }
    }
};

int main() {
    double income, percentage;
    cin >> income >> percentage;

    RentEligibility tenant(income, percentage);
    tenant.checkEligibility();

    return 0;
}