import java.io.*;
import java.util.*;

class Movie implements Serializable {
    String title;
    int year;

    Movie(String title, int year) {
        this.title = title;
        this.year = year - 3;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String title = sc.next();
        int year = sc.nextInt();
        sc.close();
        Movie m = new Movie(title, year);
        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("movie_info.ser"))) {
            out.writeObject(m);
        } catch (IOException e) {
            return;
        }
        Movie obj = null;
        try (ObjectInputStream in = new ObjectInputStream(new FileInputStream("movie_info.ser"))) {
            obj = (Movie) in.readObject();
        } catch (IOException | ClassNotFoundException e) {
            return;
        }
        System.out.println(obj.year);
    }
}
