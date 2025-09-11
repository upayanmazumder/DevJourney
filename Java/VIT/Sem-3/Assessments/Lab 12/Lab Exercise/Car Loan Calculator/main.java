import java.util.Scanner;

interface Principal {
    double getPrincipal();
}

interface InterestRate {
    double getInterestRate();
}

class Loan implements Principal, InterestRate {
    private double principal;
    private double interestRate;

    public Loan(double principal, double interestRate) {
        this.principal = principal;
        this.interestRate = interestRate;
    }

    @Override
    public double getPrincipal() {
        return principal;
    }

    @Override
    public double getInterestRate() {
        return interestRate;
    }

    public double calculateTotalInterest(int years) {
        return getPrincipal() * getInterestRate() * years;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        double carPrice = sc.nextDouble();
        double annualInterestRate = sc.nextDouble();
        int loanDuration = sc.nextInt();

        // Validate input
        if (carPrice <= 0 || annualInterestRate <= 0 || loanDuration <= 0) {
            System.out.println("Invalid input values!");
            return;
        }

        Loan carLoan = new Loan(carPrice, annualInterestRate);
        double totalInterest = carLoan.calculateTotalInterest(loanDuration);

        System.out.printf("Total interest paid: Rs.%.2f%n", totalInterest);
    }
}