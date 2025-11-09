import java.io.*;


class Student implements Serializable {
    private String name;
    private int rollNumber;
    private String enrolledCourses;

    public Student(String name, int rollNumber, String enrolledCourses) {
        this.name = name;
        this.rollNumber = rollNumber;
        this.enrolledCourses = enrolledCourses;
    }

    public String getName() {
        return name;
    }

    public int getRollNumber() {
        return rollNumber;
    }

    public String getEnrolledCourses() {
        return enrolledCourses;
    }
}


class StudentManager {
    public static boolean isValidRollNumber(int rollNumber) {
        return rollNumber > 0;
    }

    public static boolean isValidCourses(String enrolledCourses) {
        return enrolledCourses != null && !enrolledCourses.trim().isEmpty();
    }

    public static byte[] serializeStudent(Student student) throws IOException {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        ObjectOutputStream oos = new ObjectOutputStream(baos);
        oos.writeObject(student);
        oos.close();
        return baos.toByteArray();
    }

    public static Student deserializeStudent(byte[] data)
            throws IOException, ClassNotFoundException {
        ByteArrayInputStream bais = new ByteArrayInputStream(data);
        ObjectInputStream ois = new ObjectInputStream(bais);
        Student s = (Student) ois.readObject();
        ois.close();
        return s;
    }
}


public class Main {
    public static void main(String[] args) {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        String name = sc.nextLine();
        int rollNumber = sc.nextInt();
        sc.nextLine(); 
        String enrolledCourses = sc.nextLine();

        if (!StudentManager.isValidRollNumber(rollNumber)) {
            System.out.println("Invalid roll number! Must be a positive integer.");
            return;
        }

        if (!StudentManager.isValidCourses(enrolledCourses)) {
            System.out.println("Invalid courses! Must not be empty.");
            return;
        }

        try {
            Student student = new Student(name, rollNumber, enrolledCourses);
            byte[] data = StudentManager.serializeStudent(student);
            Student s = StudentManager.deserializeStudent(data);
            System.out.println("Name: " + s.getName());
            System.out.println("Roll Number: " + s.getRollNumber());
            System.out.println("Enrolled Courses: " + s.getEnrolledCourses());
        } catch (IOException | ClassNotFoundException e) {
            System.out.println("Error processing student data.");
        }
    }
}
