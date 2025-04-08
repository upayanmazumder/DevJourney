#include <iostream>
#include <string>
using namespace std;

inline int getMin(int a, int b) {
    return (a < b) ? a : b;
}

class Account;
class LoanManager;

class Account {
private:
    int accNo;
    string accHolder;
    float balance;
    static int totalAccounts;
public:
    Account() {
        accNo = 0;
        accHolder = "Unknown";
        balance = 0.0;
        totalAccounts++;
    }

    Account(int accNo, string name, float bal) {
        this->accNo = accNo;
        this->accHolder = name;
        this->balance = bal;
        totalAccounts++;
    }

    Account(const Account &a) {
        accNo = a.accNo;
        accHolder = a.accHolder;
        balance = a.balance;
        totalAccounts++;
    }

    ~Account() {
        cout << "Account " << accNo << " closed." << endl;
    }

    void deposit(float amt = 500) {
        balance += amt;
    }

    void withdraw(float amt) {
        if (amt <= balance)
            balance -= amt;
        else
            cout << "Insufficient balance!" << endl;
    }

    void showDetails() const {
        cout << "Account No: " << accNo << "\nHolder: " << accHolder << "\nBalance: ₹" << balance << endl;
    }

    static void showTotalAccounts() {
        cout << "Total Accounts: " << totalAccounts << endl;
    }

    friend void showBalance(const Account &a);

    friend class LoanManager;

    virtual void welcomeMessage() const {
        cout << "Welcome, valued customer!" << endl;
    }
};

int Account::totalAccounts = 0;

class PremiumAccount : public Account {
public:
    PremiumAccount(int accNo, string name, float bal) : Account(accNo, name, bal) {}

    void premiumBenefits() {
        cout << "You get cashback and free insurance!" << endl;
    }

    void welcomeMessage() const override {
        cout << "Welcome, premium customer!" << endl;
    }
};

void showBalance(const Account &a) {
    cout << "Balance of account: ₹" << a.balance << endl;
}

class LoanManager {
public:
    void checkLoanEligibility(Account &a) {
        if (a.balance > 5000)
            cout << "Eligible for loan!" << endl;
        else
            cout << "Not eligible for loan!" << endl;
    }
};

void batchDeposit(Account &a1, Account &a2, float amount) {
    a1.deposit(amount);
    a2.deposit(amount);
}

int main() {
    Account acc1(101, "Alice", 6000);
    Account acc2(102, "Bob", 3000);
    PremiumAccount acc3(103, "Charlie", 10000);

    acc1.showDetails();
    acc2.showDetails();
    acc3.showDetails();

    Account::showTotalAccounts();

    showBalance(acc1);

    LoanManager lm;
    lm.checkLoanEligibility(acc1);
    lm.checkLoanEligibility(acc2);

    Account *ptr = &acc3;
    ptr->welcomeMessage();

    cout << "Minimum balance between acc1 and acc2: ₹" << getMin(6000, 3000) << endl;

    batchDeposit(acc1, acc2, 1000);
    acc1.showDetails();
    acc2.showDetails();

    return 0;
}
