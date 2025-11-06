package Java.Basics.ExceptionHandling;

public class NestedTryDemo {

    public static void main(String[] args) {
        String[] words = {"alpha", null, "gamma"};

        for (int i = 0; i < words.length + 1; i++) {
            try {
                try {
                    String word = words[i];
                    System.out.println("Word length: " + word.length());
                } catch (NullPointerException ex) {
                    System.out.println("Encountered null element at index " + i);
                }
            } catch (ArrayIndexOutOfBoundsException ex) {
                System.out.println("Iteration reached beyond array bounds.");
            }
        }
    }
}
