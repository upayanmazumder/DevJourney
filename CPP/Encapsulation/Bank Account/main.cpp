#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) {
        balance = (initialBalance >= 0) ? initialBalance : 0;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) balance -= amount;
        else cout << "Insufficient balance!\n";
    }

    void displayBalance() {
        cout << "Balance: $" << balance << endl;
    }
};

int main() {
    BankAccount myAccount(500);
    myAccount.deposit(200);
    myAccount.withdraw(100);
    myAccount.displayBalance();
    return 0;
}
