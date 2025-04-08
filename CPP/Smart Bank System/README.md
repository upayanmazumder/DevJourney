1. Class: Account
Private members:

int accNo

string accHolder

float balance

Static member:

int totalAccounts — tracks number of accounts created

2. Constructors:
Default Constructor

Parameterized Constructor to set values of accNo, accHolder, balance

Copy Constructor

3. Destructor:
Should display: "Account {accNo} closed."

4. Member Functions:
void deposit(float amt)

void withdraw(float amt)

void showDetails()

static void showTotalAccounts()

5. Friend Function:
void showBalance(const Account &a) — should access private balance

6. Friend Class:
A class LoanManager that can access private members of Account

Function: checkLoanEligibility(Account &a): Eligible if balance > ₹5000

7. Inheritance:
Class PremiumAccount inherits Account

Extra function: void premiumBenefits()

8. Polymorphism:
Use virtual function void welcomeMessage() in base class.

Override it in PremiumAccount

9. Use of this Pointer in setter methods.
10. Message Passing:
Use functions to invoke behavior on objects like acc.deposit(1000);

11. Pass by Reference function to update multiple accounts at once.