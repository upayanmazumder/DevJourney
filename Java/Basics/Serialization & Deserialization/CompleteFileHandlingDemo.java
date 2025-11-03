import java.io.*;
import java.util.*;

class Student implements Serializable {
    private static final long serialVersionUID = 1L;

    private int id;
    private String name;
    private transient String password; // won't be serialized

    public Student(int id, String name, String password) {
        this.id = id;
        this.name = name;
        this.password = password;
    }

    public int getId() { return id; }
    public String getName() { return name; }
    public String getPassword() { return password; }

    @Override
    public String toString() {
        return "Student{id=" + id + ", name='" + name + "', password='" + password + "'}";
    }
}

public class CompleteFileHandlingDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<Student> students = new ArrayList<>();

        // --- TEXT FILE HANDLING ---
        try (FileWriter writer = new FileWriter("students.txt")) {
            System.out.println("Enter number of students:");
            int n = sc.nextInt();
            sc.nextLine(); // consume newline

            for (int i = 0; i < n; i++) {
                System.out.println("Enter ID, Name, Password:");
                int id = sc.nextInt();
                String name = sc.next();
                String pass = sc.next();
                sc.nextLine();

                students.add(new Student(id, name, pass));
                writer.write(id + " " + name + " " + pass + "\n");
            }

            System.out.println("Student data written to students.txt");
        } catch (IOException e) {
            System.err.println("Error writing to text file: " + e.getMessage());
        }

        // --- TEXT FILE READING ---
        System.out.println("\nReading from students.txt:");
        try (BufferedReader br = new BufferedReader(new FileReader("students.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                System.out.println("-> " + line);
            }
        } catch (IOException e) {
            System.err.println("Error reading file: " + e.getMessage());
        }

        // --- SERIALIZATION ---
        try (ObjectOutputStream oos = new ObjectOutputStream(
                new FileOutputStream("students.ser"))) {
            oos.writeObject(students);
            System.out.println("\nSerialized student list to students.ser");
        } catch (IOException e) {
            System.err.println("Serialization error: " + e.getMessage());
        }

        // --- DESERIALIZATION ---
        try (ObjectInputStream ois = new ObjectInputStream(
                new FileInputStream("students.ser"))) {

            List<Student> deserializedStudents = (List<Student>) ois.readObject();
            System.out.println("\nDeserialized student list:");

            for (Student s : deserializedStudents) {
                System.out.println("-> " + s);
            }

        } catch (IOException | ClassNotFoundException e) {
            System.err.println("Deserialization error: " + e.getMessage());
        }

        // --- FILE EXISTENCE CHECK ---
        File f = new File("students.ser");
        if (f.exists()) {
            System.out.println("\nFile '" + f.getName() + "' exists at: " + f.getAbsolutePath());
            System.out.println("File size: " + f.length() + " bytes");
        } else {
            System.out.println("File not found");
        }

        sc.close();
    }
}
