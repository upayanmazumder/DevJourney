import java.util.Scanner;
import java.lang.Math;

abstract class FinancialCalculator {
    abstract double calculateCompoundInterest(double principal, double rate, int years);

    abstract double calculateFutureValue(double principal, double rate, int years);

    abstract double calculateMonthlyLoanPayment(double principal, double rate, int years);
}

class InvestmentCalculator extends FinancialCalculator {
    @Override
    double calculateCompoundInterest(double principal, double rate, int years) {
        double futureValue = principal * Math.pow(1 + rate / 100, years);
        return futureValue - principal;
    }

    @Override
    double calculateFutureValue(double principal, double rate, int years) {
        return principal * Math.pow(1 + rate / 100, years);
    }

    @Override
    double calculateMonthlyLoanPayment(double principal, double rate, int years) {

        return 0;
    }
}

class LoanCalculator extends FinancialCalculator {
    @Override
    double calculateCompoundInterest(double principal, double rate, int years) {

        return 0;
    }

    @Override
    double calculateFutureValue(double principal, double rate, int years) {

        return 0;
    }

    @Override
    double calculateMonthlyLoanPayment(double principal, double rate, int years) {
        double monthlyRate = rate / (12 * 100);
        int totalMonths = years * 12;
        return (principal * monthlyRate) / (1 - Math.pow(1 + monthlyRate, -totalMonths));
    }
}

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        double principal = scanner.nextDouble();
        double rate = scanner.nextDouble();
        int years = scanner.nextInt();
        int choice = scanner.nextInt();

        if (choice == 1) {
            InvestmentCalculator invCalc = new InvestmentCalculator();
            double ci = invCalc.calculateCompoundInterest(principal, rate, years);
            double fv = invCalc.calculateFutureValue(principal, rate, years);
            System.out.printf("Compound Interest: %.2f\n", ci);
            System.out.printf("Future Value: %.2f\n", fv);
        } else if (choice == 2) {
            LoanCalculator loanCalc = new LoanCalculator();
            double emi = loanCalc.calculateMonthlyLoanPayment(principal, rate, years);
            System.out.printf("Monthly Loan Payment: %.2f\n", emi);
        } else {
            System.out.println("Invalid choice");
        }

        scanner.close();
    }
}