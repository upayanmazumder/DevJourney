import java.util.Scanner;

class Book {
    String title;
    String author;
    int publicationYear;

    public Book(String title, String author, int publicationYear) {
        validateTitle(title);
        validateAuthor(author);
        validatePublicationYear(publicationYear);
        this.title = title;
        this.author = author;
        this.publicationYear = publicationYear;
    }

    private void validateTitle(String title) {
        if (title.trim().isEmpty())
            throw new IllegalArgumentException("Invalid title: Title should not be empty");
    }

    private void validateAuthor(String author) {
        if (author.trim().isEmpty())
            throw new IllegalArgumentException("Invalid author: Author should not be empty");
    }

    private void validatePublicationYear(int year) {
        if (year <= 0)
            throw new IllegalArgumentException(
                    "Invalid publication year: Publication year should be a positive integer");
    }

    public void addBook() {
        System.out.println("Book added successfully");
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String title = sc.nextLine();
        String author = sc.nextLine();
        int year = Integer.parseInt(sc.nextLine());
        try {
            Book book = new Book(title, author, year);
            book.addBook();
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
    }
}