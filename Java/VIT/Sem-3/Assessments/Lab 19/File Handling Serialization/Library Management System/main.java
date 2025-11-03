import java.io.*;
import java.util.*;


class BookLending implements Serializable {
    private String title;
    private int bookID;
    private String borrowerName;

    public BookLending(String title, int bookID, String borrowerName) {
        this.title = title;
        this.bookID = bookID;
        this.borrowerName = borrowerName;
    }

    public String getTitle() {
        return title;
    }

    public int getBookID() {
        return bookID;
    }

    public String getBorrowerName() {
        return borrowerName;
    }
}


class BookLendingManager {

    public boolean isValidBookID(String bookIDStr) {
        try {
            int id = Integer.parseInt(bookIDStr.trim());
            return id > 0;
        } catch (NumberFormatException e) {
            return false;
        }
    }

    public boolean isValidBorrowerName(String name) {
        return name != null && !name.trim().isEmpty();
    }

    public byte[] serialize(BookLending book) throws IOException {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        ObjectOutputStream oos = new ObjectOutputStream(baos);
        oos.writeObject(book);
        oos.close();
        return baos.toByteArray();
    }

    public BookLending deserialize(byte[] data) throws IOException, ClassNotFoundException {
        ByteArrayInputStream bais = new ByteArrayInputStream(data);
        ObjectInputStream ois = new ObjectInputStream(bais);
        BookLending book = (BookLending) ois.readObject();
        ois.close();
        return book;
    }
}


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BookLendingManager manager = new BookLendingManager();

        String title = sc.nextLine();
        String bookIDStr = sc.nextLine();
        String borrowerName = sc.nextLine();

        
        if (!manager.isValidBookID(bookIDStr)) {
            System.out.print("Invalid book ID! Must be a positive integer.");
            return;
        }

        
        if (!manager.isValidBorrowerName(borrowerName)) {
            System.out.print("Invalid borrower name!");
            return;
        }

        try {
            int id = Integer.parseInt(bookIDStr.trim());
            BookLending book = new BookLending(title, id, borrowerName);

            
            byte[] data = manager.serialize(book);
            BookLending b = manager.deserialize(data);

            
            System.out.println("Book Title: " + b.getTitle());
            System.out.println("Book ID: " + b.getBookID());
            System.out.print("Borrower's Name: " + b.getBorrowerName());
        } catch (Exception e) {
            System.out.print("Invalid book ID! Must be a positive integer.");
        }
    }
}
