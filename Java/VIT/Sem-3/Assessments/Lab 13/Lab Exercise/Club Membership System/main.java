import java.util.Scanner;

class AgeNotValidException extends Exception {
    public AgeNotValidException(String message) {
        super(message);
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int age = sc.nextInt();
        sc.close();

        try {
            if (age < 18) {
                throw new AgeNotValidException("Age is less than 18. You are not eligible.");
            } else {
                System.out.println("Age is valid! You are eligible.");
            }
        } catch (AgeNotValidException e) {
            System.out.println(e.getMessage());
        }
    }
}