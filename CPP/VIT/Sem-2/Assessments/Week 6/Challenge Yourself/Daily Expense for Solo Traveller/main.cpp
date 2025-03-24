#include <iostream>
#include <iomanip>

using namespace std;

class TravelPlan {
public:
    int days;
    double budget;

    TravelPlan(int d, double b) : days(d), budget(b) {}
};

class BudgetTravel : public TravelPlan {
public:
    double baseExpense;

    BudgetTravel(int d, double b) : TravelPlan(d, b) {
        baseExpense = 1.2 * (budget / days);
    }
};

class SoloTravel : public BudgetTravel {
private:
    double lodgingExpense, foodExpense;

public:
    SoloTravel(int d, double b, double l, double f) 
        : BudgetTravel(d, b), lodgingExpense(l), foodExpense(f) {}

    void calculateExpense() {
        double totalExpense = baseExpense + lodgingExpense + foodExpense;
        cout << "Rs. " << fixed << setprecision(2) << totalExpense << endl;
    }
};

int main() {
    int days;
    double budget, lodging, food;

    cin >> days;
    cin >> budget >> lodging >> food;

    SoloTravel trip(days, budget, lodging, food);
    trip.calculateExpense();

    return 0;
}