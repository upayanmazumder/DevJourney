package Java.Basics.ExceptionHandling;

public class BasicTryCatch {

    public static void main(String[] args) {
        int numerator = 10;
        int denominator = 0;

        try {
            int result = numerator / denominator;
            System.out.println("Result: " + result);
        } catch (ArithmeticException ex) {
            System.out.println("Cannot divide by zero. Reason: " + ex.getMessage());
        }

        System.out.println("Program continues after handling the exception.");
    }
}
