import java.util.Scanner;

class Main {

    public static <T> void genericDisplay(T element) {
        System.out.println(element.getClass().getName() + " = " + element);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int integerValue = scanner.nextInt();
        double doubleValue = scanner.nextDouble();

        scanner.close();

        genericDisplay(integerValue);
        genericDisplay(doubleValue);
    }
}