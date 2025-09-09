import java.util.Scanner;
import java.text.DecimalFormat;

class Employee {
    String name;
    double hourlyRate;

    Employee(String name, double hourlyRate) {
        this.name = name;
        this.hourlyRate = hourlyRate;
    }
}

class HourlyEmployee extends Employee {

    int hoursWorked;

    HourlyEmployee(String name, double hourlyRate, int hoursWorked) {
        super(name, hourlyRate);
        this.hoursWorked = hoursWorked;
    }

    double calculateWeeklySalary() {
        double salary = 0;
        if (hoursWorked <= 40) {
            salary = hoursWorked * hourlyRate;
        } else {
            salary = 40 * hourlyRate + (hoursWorked - 40) * hourlyRate * 1.5;
        }
        return salary;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String name = scanner.nextLine();
        double hourlyRate = scanner.nextDouble();
        int hoursWorked = scanner.nextInt();
        HourlyEmployee employee = new HourlyEmployee(name, hourlyRate,
                hoursWorked);
        double weeklySalary = employee.calculateWeeklySalary();
        DecimalFormat df = new DecimalFormat("#.00");
        String formattedSalary = df.format(weeklySalary);
        System.out.println("Weekly Salary: Rs." + formattedSalary);
        scanner.close();
    }
}