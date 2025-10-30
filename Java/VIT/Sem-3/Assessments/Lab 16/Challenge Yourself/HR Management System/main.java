import java.io.*;
import java.util.*;

class Employee implements Serializable {
    int id;
    String name;
    String dept;
    double salary;

    Employee(int id, String name, String dept, double salary) {
        this.id = id;
        this.name = name;
        this.dept = dept;
        this.salary = salary;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Employee[] e = new Employee[n];
        for (int i = 0; i < n; i++) {
            int id = sc.nextInt();
            String name = sc.next();
            String dept = sc.next();
            double sal = sc.nextDouble();
            e[i] = new Employee(id, name, dept, sal);
        }
        double x = sc.nextDouble();
        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("employees.ser"))) {
            out.writeObject(e);
        } catch (IOException ex) {
            return;
        }
        Employee[] employees = null;
        try (ObjectInputStream in = new ObjectInputStream(new FileInputStream("employees.ser"))) {
            employees = (Employee[]) in.readObject();
        } catch (Exception ex) {
            return;
        }
        boolean found = false;
        for (Employee emp : employees) {
            if (emp.salary > x) {
                System.out.println(emp.id + " " + emp.name + " " + emp.dept + " " + emp.salary);
                found = true;
            }
        }
        if (!found)
            System.out.println("No employees found above threshold");
    }
}
