import java.util.Scanner;

class StringManipulator {
    // Method 1: Simple concatenation
    public static String concatenate(String s1, String s2) {
        return s1 + s2;
    }

    // Method 2: Concatenation with reversal (excluding spaces)
    public static String concatenate(String s1, String s2, boolean reverse) {
        if (reverse) {
            String combined = s1 + s2;
            String noSpaces = combined.replace(" ", "");
            return new StringBuilder(noSpaces).reverse().toString();
        }
        return s1 + s2;
    }
}

class Main {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();

        for (int i = 1; i <= t; i++) {

            int operation = scanner.nextInt();

            scanner.nextLine();

            String str1 = scanner.nextLine();

            String str2 = scanner.nextLine();

            String result = (operation == 1)

                    ? StringManipulator.concatenate(str1, str2)

                    : StringManipulator.concatenate(str1, str2, true);

            System.out.println(result);

        }

    }

}