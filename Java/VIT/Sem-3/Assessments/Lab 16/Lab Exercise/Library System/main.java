import java.io.*;
import java.util.*;

class Book implements Serializable {
    int id;
    String title;
    String author;
    int copies;

    Book(int id, String title, String author, int copies) {
        this.id = id;
        this.title = title;
        this.author = author;
        this.copies = copies;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Book> books = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int id = sc.nextInt();
            String title = sc.next();
            String author = sc.next();
            int copies = sc.nextInt();
            books.add(new Book(id, title, author, copies));
        }
        int threshold = sc.nextInt();
        sc.close();
        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("books.ser"))) {
            out.writeObject(books);
        } catch (IOException e) {
            return;
        }
        ArrayList<Book> list = null;
        try (ObjectInputStream in = new ObjectInputStream(new FileInputStream("books.ser"))) {
            list = (ArrayList<Book>) in.readObject();
        } catch (IOException | ClassNotFoundException e) {
            return;
        }
        boolean found = false;
        for (Book b : list) {
            if (b.copies > threshold) {
                System.out.println(b.id + " " + b.title + " " + b.author + " " + b.copies);
                found = true;
            }
        }
        if (!found)
            System.out.println("No books found above threshold");
    }
}
