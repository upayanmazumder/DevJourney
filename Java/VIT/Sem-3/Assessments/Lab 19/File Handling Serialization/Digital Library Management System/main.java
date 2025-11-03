import java.io.*;import java.util.*;

class Book implements Serializable {
    String title;
    String author;
    int pages;
    public Book(String title, String author, int pages) {
        this.title = title;
        this.author = author;
        this.pages = pages;
    }
}

class LibraryManager {
    private final String filename = "books.ser";
    public void saveBooks(Book[] newBooks) {
        try {
            List<Book> allBooks = new ArrayList<>();
            File file = new File(filename);
            if (file.exists() && file.length() > 0) {
                ObjectInputStream ois = new ObjectInputStream(new FileInputStream(file));
                allBooks = new ArrayList<>(Arrays.asList((Book[]) ois.readObject()));
                ois.close();
            }
            allBooks.addAll(Arrays.asList(newBooks));
            ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(filename));
            oos.writeObject(allBooks.toArray(new Book[0]));
            oos.close();
        } catch (Exception e) {}
    }
    public Book[] loadBooks() {
        try {
            File file = new File(filename);
            if (!file.exists() || file.length() == 0) return new Book[0];
            ObjectInputStream ois = new ObjectInputStream(new FileInputStream(file));
            Book[] books = (Book[]) ois.readObject();
            ois.close();
            return books;
        } catch (Exception e) {
            return new Book[0];
        }
    }
    public void analyzeBooks(Book[] books) {
        if (books.length == 0) return;
        Arrays.sort(books, Comparator.comparingInt(b -> b.pages));
        System.out.println("Books Sorted by Page Count:");
        for (Book b : books) System.out.println(b.title);
        System.out.println();
        Book longest = books[0];
        for (Book b : books) {
            if (b.title.length() > longest.title.length()) longest = b;
        }
        System.out.println("Book with Longest Title: " + longest.title);
        double total = 0;
        for (Book b : books) total += b.pages;
        System.out.printf("%nAverage Number of Pages: %.2f", total / books.length);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Book[] newBooks = new Book[n];
        for (int i = 0; i < n; i++) {
            String title = sc.next();
            String author = sc.next();
            int pages = sc.nextInt();
            newBooks[i] = new Book(title, author, pages);
        }
        LibraryManager manager = new LibraryManager();
        Book[] existingBooks = manager.loadBooks();
        Book[] allBooks = Arrays.copyOf(existingBooks, existingBooks.length + newBooks.length);
        System.arraycopy(newBooks, 0, allBooks, existingBooks.length, newBooks.length);
        manager.saveBooks(allBooks);
        manager.analyzeBooks(allBooks);
    }
}
