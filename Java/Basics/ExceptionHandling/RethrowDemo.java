package Java.Basics.ExceptionHandling;

public class RethrowDemo {

    public static void main(String[] args) {
        try {
            process("abc");
            process(null);
        } catch (IllegalArgumentException ex) {
            System.out.println("Handled in main: " + ex.getMessage());
        }
    }

    private static void process(String text) {
        try {
            if (text == null) {
                throw new NullPointerException("Input text is null");
            }
            System.out.println("Processed text: " + text.toUpperCase());
        } catch (NullPointerException ex) {
            throw new IllegalArgumentException("Invalid input passed to process", ex);
        }
    }
}
