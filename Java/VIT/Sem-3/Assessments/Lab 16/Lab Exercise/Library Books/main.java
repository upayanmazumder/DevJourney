import java.io.*;
import java.util.*;

class Book implements Serializable {
    int id;
    String title;
    String author;

    Book(int id, String title, String author) {
        this.id = id;
        this.title = title;
        this.author = author;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        Book[] books = new Book[n];
        for (int i = 0; i < n; i++) {
            int id = Integer.parseInt(sc.nextLine());
            String title = sc.nextLine();
            String author = sc.nextLine();
            books[i] = new Book(id, title, author);
        }
        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("books.dat"))) {
            out.writeObject(books);
        } catch (IOException e) {
            return;
        }
        System.out.println("Successfully serialized " + n + " books to books.dat");
        System.out.println("Summary of Books:");
        for (int i = 0; i < n; i++) {
            System.out.println((i + 1) + ". [BookId: " + books[i].id + "] Title: " + books[i].title + ", Author: "
                    + books[i].author);
        }
    }
}
