import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        char ch = sc.nextLine().charAt(0);
        int count = 0;

        for (int i = 0; i < input.length(); i++) {
            if (input.charAt(i) == ch) {
                count++;
            }
        }

        System.out.println("The character '" + ch + "' occurs " + count + " times.");
    }
}