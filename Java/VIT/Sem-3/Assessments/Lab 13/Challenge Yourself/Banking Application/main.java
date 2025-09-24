import java.util.Scanner;

class LoanOverdueException extends Exception {
    public LoanOverdueException(String message) {
        super(message);
    }
}

class NegativeLoanRepaymentAmountException extends Exception {
    public NegativeLoanRepaymentAmountException(String message) {
        super(message);
    }
}

class InsufficientFundsForLoanRepaymentException extends Exception {
    public InsufficientFundsForLoanRepaymentException(String message) {
        super(message);
    }
}

class Main {
    static void processWithdrawal(double balance, double loanAmount, double minLoanRepayment, int daysOverdue,
            double amount)
            throws LoanOverdueException, NegativeLoanRepaymentAmountException,
            InsufficientFundsForLoanRepaymentException {
        if (daysOverdue > 60)
            throw new LoanOverdueException("Loan is overdue by more than 60 days. Immediate payment required.");
        if (amount < 0)
            throw new NegativeLoanRepaymentAmountException("Loan repayment amount cannot be negative.");
        double remainingBalance = balance - amount;
        if (remainingBalance < minLoanRepayment)
            throw new InsufficientFundsForLoanRepaymentException(
                    "Insufficient funds to cover loan repayment after withdrawal.");
        balance = remainingBalance - minLoanRepayment;
        loanAmount -= minLoanRepayment;
        System.out.printf("Remaining Balance: %.2f\n", balance);
        System.out.printf("Remaining Loan Amount: %.2f\n", loanAmount);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double balance = Double.parseDouble(sc.nextLine());
        double loanAmount = Double.parseDouble(sc.nextLine());
        double minLoanRepayment = Double.parseDouble(sc.nextLine());
        int daysOverdue = Integer.parseInt(sc.nextLine());
        double amount = Double.parseDouble(sc.nextLine());
        try {
            processWithdrawal(balance, loanAmount, minLoanRepayment, daysOverdue, amount);
        } catch (LoanOverdueException | NegativeLoanRepaymentAmountException
                | InsufficientFundsForLoanRepaymentException e) {
            System.out.println(e.getMessage());
        }
    }
}