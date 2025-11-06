package Java.Basics.ExceptionHandling;

public class ExceptionPropagationDemo {

    public static void main(String[] args) {
        try {
            levelOne();
        } catch (IllegalStateException ex) {
            System.out.println("Caught at main: " + ex.getMessage());
        }
    }

    private static void levelOne() {
        levelTwo();
    }

    private static void levelTwo() {
        throw new IllegalStateException("Problem occurred deep in the call stack");
    }
}
