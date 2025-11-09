import java.io.*;
import java.util.*;


class Student implements Serializable {
    private static final long serialVersionUID = 1L;
    private String name;
    private int studentID;
    private String enrolledCourses;

    public Student(String name, int studentID, String enrolledCourses) {
        this.name = name;
        this.studentID = studentID;
        this.enrolledCourses = enrolledCourses;
    }

    public String getName() {
        return name;
    }

    public int getStudentID() {
        return studentID;
    }

    public String getEnrolledCourses() {
        return enrolledCourses;
    }
}

class StudentManager {
    public static boolean isValidStudentID(String idStr) {
        try {
            int id = Integer.parseInt(idStr);
            return id > 0;
        } catch (NumberFormatException e) {
            return false;
        }
    }

    public static boolean isValidCourses(String courses) {
        return courses != null && !courses.trim().isEmpty();
    }

    public static byte[] serializeStudent(Student s) {
        try {
            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            ObjectOutputStream oos = new ObjectOutputStream(baos);
            oos.writeObject(s);
            oos.close();
            return baos.toByteArray();
        } catch (Exception e) {
            return null;
        }
    }

    public static Student deserializeStudent(byte[] data) {
        try {
            ByteArrayInputStream bais = new ByteArrayInputStream(data);
            ObjectInputStream ois = new ObjectInputStream(bais);
            Student s = (Student) ois.readObject();
            ois.close();
            return s;
        } catch (Exception e) {
            return null;
        }
    }

    public static void processStudent(String name, String studentIDString, String courses) {
        if (!isValidStudentID(studentIDString)) {
            System.out.println("Invalid student ID! Must be a positive integer.");
            return;
        }
        if (!isValidCourses(courses)) {
            System.out.println("Invalid courses! Must not be empty.");
            return;
        }

        int id = Integer.parseInt(studentIDString);
        Student student = new Student(name, id, courses);
        byte[] data = serializeStudent(student);
        Student s = deserializeStudent(data);

        if (s != null) {
            System.out.println("Name: " + s.getName());
            System.out.println("Student ID: " + s.getStudentID());
            System.out.println("Enrolled Courses: " + s.getEnrolledCourses());
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String name = sc.nextLine();
        String studentIDString = sc.nextLine();
        String enrolledCourses = sc.nextLine();
        StudentManager.processStudent(name, studentIDString, enrolledCourses);
    }
}
