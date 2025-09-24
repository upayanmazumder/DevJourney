import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String original = sc.nextLine();
        String substring = sc.nextLine();
        int position = Integer.parseInt(sc.nextLine());
        if (position < 0 || position > original.length()) {
            System.out.println("Invalid position.");
        } else {
            StringBuilder sb = new StringBuilder(original);
            sb.insert(position, substring);
            System.out.println(sb.toString());
        }
    }
}