#include <iostream>
using namespace std;

template <typename T>
class BankAccount {
    T balance;
    T interestRate;

public:
    void setBalance(T b) {
        balance = b;
    }

    void setInterestRate(T rate) {
        interestRate = rate;
    }

    T getBalance() const {
        return balance;
    }

    T getInterestRate() const {
        return interestRate;
    }

    T calculateInterest() const {
        return balance * interestRate / 100;
    }

    T balanceAfterOneYear() const {
        return balance + calculateInterest();
    }
};

int main() {
    int balance, interestRate;
    cin >> balance >> interestRate;

    BankAccount<int> account;
    account.setBalance(balance);
    account.setInterestRate(interestRate);

    int interest = account.calculateInterest();
    int finalBalance = account.balanceAfterOneYear();

    cout << "Balance after one year: " << finalBalance << endl;
    cout << "Interest earned after one year: " << interest << endl;

    return 0;
}