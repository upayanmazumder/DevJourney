import java.util.Scanner;
import java.text.DecimalFormat;

class Employee {
    String name;
    int employeeID;

    Employee(String name, int employeeID) {
        this.name = name;
        this.employeeID = employeeID;
    }
}

class Manager extends Employee {
    double monthlySalary;

    Manager(String name, int employeeID, double monthlySalary) {
        super(name, employeeID);
        this.monthlySalary = monthlySalary;
    }

    double calculateAnnualSalary() {
        return monthlySalary * 12;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("0.00");
        String name = scanner.nextLine();
        int employeeID = scanner.nextInt();
        double salary = scanner.nextDouble();
        Manager manager = new Manager(name, employeeID, salary);
        System.out.println("Name: " + manager.name);
        System.out.println("Annual Salary: Rs. " +
                df.format(manager.calculateAnnualSalary()));

        scanner.close();
    }
}