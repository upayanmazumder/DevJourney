import java.util.Scanner;

class InvalidEmailException extends Exception {
    public InvalidEmailException(String message) {
        super(message);
    }
}

class Main {
    static void validateEmail(String email) throws InvalidEmailException {
        if (!email.equals(email.trim()) || email.chars().filter(ch -> ch == '@').count() != 1)
            throw new InvalidEmailException("Error: Invalid email format.");
        String[] parts = email.split("@");
        if (parts.length != 2 || parts[0].isEmpty() || parts[1].isEmpty() || !parts[1].contains("."))
            throw new InvalidEmailException("Error: Invalid email format.");
        System.out.println("Email address is valid!");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String email = sc.nextLine();
        try {
            validateEmail(email);
        } catch (InvalidEmailException e) {
            System.out.println(e.getMessage());
        }
    }
}