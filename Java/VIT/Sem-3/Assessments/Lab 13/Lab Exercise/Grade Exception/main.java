import java.util.Scanner;

class GradeException extends Exception {
    public GradeException(String message) {
        super(message);
    }
}

class Student {
    String name;
    int age;
    int grade;

    public Student(String name, int age, int grade) {
        this.name = name;
        this.age = age;
        this.grade = grade;
    }

    public void checkGrade() throws GradeException {
        if (grade < 40) {
            throw new GradeException("Grade is below 40");
        } else {
            System.out.println("Name: " + name + " Age: " + age + " Grade: " + grade);
        }
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String name = sc.nextLine();
        int age = sc.nextInt();
        int grade = sc.nextInt();
        sc.close();

        Student student = new Student(name, age, grade);

        try {
            student.checkGrade();
        } catch (GradeException e) {
            System.out.println(e.getMessage());
        }
    }
}