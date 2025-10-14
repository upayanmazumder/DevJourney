import java.io.*;
import java.util.Scanner;

class SalaryReader {
    private String name;
    private int basicSalary, bonus, totalSalary;

    public void writeSalary(String filename, Scanner sc) {
        try {
            name = sc.nextLine();
            basicSalary = Integer.parseInt(sc.nextLine());
            bonus = Integer.parseInt(sc.nextLine());
            totalSalary = basicSalary + bonus;

            FileWriter writer = new FileWriter(filename);
            writer.write("Employee Salary Details:\n");
            writer.write("Name: " + name + "\n");
            writer.write("Basic Salary: " + basicSalary + "\n");
            writer.write("Bonus: " + bonus + "\n");
            writer.write("Total Salary: " + totalSalary + "\n");
            writer.close();
        } catch (IOException e) {
            System.out.println("Error writing file: " + e.getMessage());
        }
    }

    public void readAndDisplay(String sourceFile, String destFile) {
        try {
            FileReader fr = new FileReader(sourceFile);
            FileWriter fw = new FileWriter(destFile);

            int ch;
            while ((ch = fr.read()) != -1) {
                fw.write(ch);
                System.out.print((char) ch);
            }

            fr.close();
            fw.close();
        } catch (IOException e) {
            System.out.println("Error reading/writing file: " + e.getMessage());
        }
    }
}

class SalaryMain {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String name = scanner.nextLine();
        int basicSalary = Integer.parseInt(scanner.nextLine());
        int bonus = Integer.parseInt(scanner.nextLine());
        int totalSalary = basicSalary + bonus;
        String sourceFile = "salary_source.txt";
        String destinationFile = "salary_destination.txt";

        SalaryReader reader = new SalaryReader();
        reader.writeSalary(sourceFile, scanner);
        reader.readAndDisplay(sourceFile, destinationFile);

        scanner.close();
    }
}
