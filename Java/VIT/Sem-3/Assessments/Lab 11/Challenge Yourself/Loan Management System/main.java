class LoanCalculator {
    public double amortizationSchedule(double principal, double annualRate, int months) {
        double monthlyRate = annualRate / 12 / 100;
        double emi = (principal * monthlyRate * Math.pow(1 + monthlyRate,
                months)) /
                (Math.pow(1 + monthlyRate, months) - 1);
        return emi;
    }
}

class AdvancedLoanCalculator extends LoanCalculator {
    @Override
    public double amortizationSchedule(double principal, double annualRate, int months) {
        double monthlyRate = annualRate / 12 / 100;
        double emi = super.amortizationSchedule(principal, annualRate, months);
        double remainingBalance = principal;
        double totalInterest = 0.0;

        for (int month = 1; month <= months; month++) {
            double interestPayment = remainingBalance * monthlyRate;
            double principalPayment = emi - interestPayment;
            remainingBalance -= principalPayment;
            if (month == months)
                remainingBalance = 0.0;
            totalInterest += interestPayment;
            System.out.printf("Month %d:%n", month);
            System.out.printf("Monthly Payment: %.2f%n", emi);
            System.out.printf("Principal Payment: %.2f%n", principalPayment);
            System.out.printf("Interest Payment: %.2f%n", interestPayment);
            System.out.printf("Remaining Balance: %.2f%n%n", remainingBalance);
        }
        System.out.printf("Total Interest Paid: %.2f%n", totalInterest);
        return emi;
    }
}
