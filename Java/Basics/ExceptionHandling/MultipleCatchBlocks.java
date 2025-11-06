package Java.Basics.ExceptionHandling;

public class MultipleCatchBlocks {

    public static void main(String[] args) {
        String numberText = "42";
        String[] values = {"10", "20"};

        try {
            int index = Integer.parseInt(numberText);
            int value = Integer.parseInt(values[index]);
            System.out.println("Value at index " + index + " is " + value);
        } catch (NumberFormatException ex) {
            System.out.println("Failed to parse integer: " + ex.getMessage());
        } catch (ArrayIndexOutOfBoundsException ex) {
            System.out.println("Index is outside the array: " + ex.getMessage());
        }
    }
}
