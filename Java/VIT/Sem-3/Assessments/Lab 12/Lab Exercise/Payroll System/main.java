import java.util.Scanner;

interface Employee {
    double earnings(double basicSalary);

    double deductions(double basicSalary);

    double bonus(double basicSalary);
}

abstract class Manager implements Employee {
    @Override
    public double earnings(double basicSalary) {
        return basicSalary + (0.8 * basicSalary) + (0.15 * basicSalary);
    }

    @Override
    public double deductions(double basicSalary) {
        return 0.12 * basicSalary;
    }
}

class Substaff extends Manager {
    @Override
    public double bonus(double basicSalary) {
        return 0.5 * basicSalary;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double basicSalary = scanner.nextDouble();
        Substaff substaff = new Substaff();

        double earnings = substaff.earnings(basicSalary);
        double deductions = substaff.deductions(basicSalary);
        double bonus = substaff.bonus(basicSalary);

        System.out.println("Earnings: " + String.format("%.2f", earnings));
        System.out.println("Deductions: " + String.format("%.2f", deductions));
        System.out.println("Bonus: " + String.format("%.2f", bonus));

        scanner.close();
    }
}