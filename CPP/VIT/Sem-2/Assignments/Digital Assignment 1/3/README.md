You  are  developing  a  Bank  Management  System  with  multiple  functionalities. Create a base class "Person" with data members such as name, age, and address. Inherit two classes from "Person": 
• "BankAccount" with members account number, balance, and methods for deposit and withdrawal. 
• "Loan" with members loan amount, interest rate, and methods to calculate loan EMI (Equated Monthly Installment). 
Create  a  derived  class  "Customer"  that  inherits  from  both  "BankAccount"  and "Loan"  (demonstrating  multipath  inheritance).  Implement  appropriate  methods 
to: 
• Perform deposit and withdrawal operations, checking for sufficient balance. 
• Calculate and display loan EMI based on the given interest rate and loan amount. 
• Display  customer  details  along  with  their  account  balance  and  loan information. 
Write  a  C++  program  to  implement  this  scenario  and  resolve  any  ambiguity caused due to inheritance.