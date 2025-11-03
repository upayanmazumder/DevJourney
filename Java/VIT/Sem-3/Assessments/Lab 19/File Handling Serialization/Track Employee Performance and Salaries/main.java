import java.io.*;
import java.util.*;


class Employee implements Serializable {
    int id;
    String name;
    double salary;

    public Employee(int id, String name, double salary) {
        this.id = id;
        this.name = name;
        this.salary = salary;
    }

    public String toString() {
        return "Employee[ID=" + id + ", Name=" + name + ", Salary=" + salary + "]";
    }
}


class EmployeeManager {
    public void serializeEmployees(Employee[] employees, String filename) throws IOException {
        ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(filename));
        oos.writeObject(employees);
        oos.close();
    }

    public Employee[] deserializeEmployees(String filename) throws IOException, ClassNotFoundException {
        ObjectInputStream ois = new ObjectInputStream(new FileInputStream(filename));
        Employee[] employees = (Employee[]) ois.readObject();
        ois.close();
        return employees;
    }

    public Employee findHighestSalaryEmployee(Employee[] employees) {
        if (employees == null || employees.length == 0) return null;
        Employee top = employees[0];
        for (Employee e : employees) {
            if (e.salary > top.salary) top = e;
        }
        return top;
    }
}


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        EmployeeManager manager = new EmployeeManager();
        try {
            int n = sc.nextInt();
            Employee[] employees = new Employee[n];

            for (int i = 0; i < n; i++) {
                int id = sc.nextInt();
                String name = sc.next();
                double salary = sc.nextDouble();
                employees[i] = new Employee(id, name, salary);
            }

            String filename = "employees.ser";
            manager.serializeEmployees(employees, filename);
            Employee[] deserializedEmployees = manager.deserializeEmployees(filename);

            Employee topEmployee = manager.findHighestSalaryEmployee(deserializedEmployees);
            if (topEmployee != null)
                System.out.print("Highest Salary: " + topEmployee);
        } catch (Exception e) {
            System.out.print("");
        }
    }
}
