#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Person {
public:
    string name, address;
    int age;

    void getPersonData() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter address: ";
        getline(cin, address);
    }
};

class BankAccount : virtual public Person {
protected:
    int accountNumber;
    float balance;

public:
    void getAccountData() {
        cout << "Enter account number: ";
        cin >> accountNumber;
        cout << "Enter initial balance: ";
        cin >> balance;
    }

    void deposit(float amount) {
        balance += amount;
        cout << "Amount deposited. New balance: " << balance << endl;
    }

    void withdraw(float amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Amount withdrawn. New balance: " << balance << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }

    float getBalance() {
        return balance;
    }
};

class Loan : virtual public Person {
protected:
    float loanAmount, interestRate;

public:
    void getLoanData() {
        cout << "Enter loan amount: ";
        cin >> loanAmount;
        cout << "Enter interest rate (%): ";
        cin >> interestRate;
    }

    float calculateEMI(int months) {
        float r = interestRate / (12 * 100);
        return (loanAmount * r * pow(1 + r, months)) / (pow(1 + r, months) - 1);
    }

    void showLoanInfo(int months) {
        cout << "Loan Amount: " << loanAmount << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << "Loan EMI (" << months << " months): " << calculateEMI(months) << endl;
    }
};

class Customer : public BankAccount, public Loan {
public:
    void showDetails(int months) {
        cout << "\n--- Customer Details ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: " << balance << endl;
        showLoanInfo(months);
    }
};

int main() {
    Customer c;
    c.getPersonData();
    c.getAccountData();
    c.getLoanData();

    int months;
    cout << "Enter loan tenure in months: ";
    cin >> months;

    float depAmt, withAmt;
    cout << "Enter amount to deposit: ";
    cin >> depAmt;
    c.deposit(depAmt);

    cout << "Enter amount to withdraw: ";
    cin >> withAmt;
    c.withdraw(withAmt);

    c.showDetails(months);
    return 0;
}
