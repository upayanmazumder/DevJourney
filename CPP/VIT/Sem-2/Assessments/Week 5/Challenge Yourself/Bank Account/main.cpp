#include <iostream>
#include <iomanip>
using namespace std;

class BankAccount {
    static float rate;
public:
    static void setInterestRate(float r) { rate = r; }
    static void calculateInterest(float balance) {
        cout << fixed << setprecision(2) << balance * rate << endl;
    }
};

float BankAccount::rate = 0.03;

int main() {
    float r, b;
    cin >> r >> b;
    BankAccount::setInterestRate(r);
    BankAccount::calculateInterest(b);
}