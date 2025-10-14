import java.io.*;
import java.util.Scanner;

class StudentExamReport {
    private String name;
    private int sub1, sub2, sub3;
    private double average;

    public void writeReport(String filename, Scanner sc) {
        try {
            name = sc.nextLine();
            sub1 = sc.nextInt();
            sub2 = sc.nextInt();
            sub3 = sc.nextInt();
            average = (sub1 + sub2 + sub3) / 3.0;

            FileWriter writer = new FileWriter(filename);
            writer.write("Student Exam Report:\n");
            writer.write("Name: " + name + "\n");
            writer.write("Subject 1: " + sub1 + "\n");
            writer.write("Subject 2: " + sub2 + "\n");
            writer.write("Subject 3: " + sub3 + "\n");
            writer.write(String.format("Average Marks: %.2f\n", average));
            writer.close();
        } catch (IOException e) {
            System.out.println("Error writing file: " + e.getMessage());
        }
    }

    public void readAndCopyReport(String sourceFile, String destFile) {
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

class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        String source = "result_source.txt";
        String destination = "result_destination.txt";

        StudentExamReport report = new StudentExamReport();
        report.writeReport(source, scanner);
        report.readAndCopyReport(source, destination);

        scanner.close();
    }
}