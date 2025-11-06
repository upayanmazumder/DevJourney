package Java.Basics.ExceptionHandling;

public class CustomExceptionDemo {

    public static void main(String[] args) {
        try {
            validateScore(85);
            validateScore(150);
        } catch (InvalidScoreException ex) {
            System.out.println("Validation failed: " + ex.getMessage());
        }
    }

    private static void validateScore(int score) throws InvalidScoreException {
        if (score < 0 || score > 100) {
            throw new InvalidScoreException("Score must be between 0 and 100. Provided: " + score);
        }
        System.out.println("Score " + score + " is valid.");
    }
}
