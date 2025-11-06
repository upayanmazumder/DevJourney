package Java.Basics.ExceptionHandling;

public class FinallyBlockDemo {

    public static void main(String[] args) {
        System.out.println(readValue("123"));
        System.out.println(readValue(null));
    }

    private static String readValue(String text) {
        String message = "Starting read";
        try {
            if (text == null) {
                throw new IllegalArgumentException("Text cannot be null");
            }
            return "Parsed text: " + text;
        } catch (IllegalArgumentException ex) {
            return "Handled error: " + ex.getMessage();
        } finally {
            // Finally always runs, useful for cleanup such as closing resources.
            System.out.println("Cleanup step executed for input: " + text);
        }
    }
}
