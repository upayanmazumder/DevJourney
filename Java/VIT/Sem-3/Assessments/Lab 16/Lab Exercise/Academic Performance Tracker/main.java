import java.io.*;
import java.util.*;

class Grade implements Serializable {
    String subject;
    int score;

    Grade(String subject, int score) {
        this.subject = subject;
        this.score = score;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String subject = sc.next();
        int score = sc.nextInt();
        sc.close();
        Grade g = new Grade(subject, score);
        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("grades.ser"))) {
            out.writeObject(g);
        } catch (IOException e) {
            return;
        }
        Grade obj = null;
        try (ObjectInputStream in = new ObjectInputStream(new FileInputStream("grades.ser"))) {
            obj = (Grade) in.readObject();
        } catch (IOException | ClassNotFoundException e) {
            return;
        }
        if (obj.score >= 90)
            System.out.println("Excellent");
        else if (obj.score > 70)
            System.out.println("Good");
        else
            System.out.println("Needs Improvement");
    }
}
