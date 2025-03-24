#include <iostream>
#include <iomanip>
using namespace std;

class Account {
protected:
    string accountNumber;
    double balance;

public:
    Account(string accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {}

    void deposit(double amount) {
        balance += amount;
        cout << fixed << setprecision(2);
        cout << "Deposited " << amount << " successfully." << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << fixed << setprecision(2);
            cout << "Withdrawn " << amount << " successfully." << endl;
        }
    }

    double getBalance() {
        return balance;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(string accNum, double initialBalance, double rate)
        : Account(accNum, initialBalance), interestRate(rate) {}

    void addInterest() {
        double interest = (balance * interestRate) / 100;
        balance += interest;
        cout << fixed << setprecision(2);
        cout << "Interest added: " << interest << endl;
    }

    void displayBalance() {
        cout << fixed << setprecision(2);
        cout << "Savings Account Balance: " << balance << endl;
    }
};

int main() {
    string accountNumber;
    double initialBalance, interestRate, depositAmount, withdrawalAmount;

    cin >> accountNumber >> initialBalance >> interestRate >> depositAmount >> withdrawalAmount;

    SavingsAccount account(accountNumber, initialBalance, interestRate);

    account.deposit(depositAmount);
    account.withdraw(withdrawalAmount);
    account.addInterest();
    account.displayBalance();

    return 0;
}