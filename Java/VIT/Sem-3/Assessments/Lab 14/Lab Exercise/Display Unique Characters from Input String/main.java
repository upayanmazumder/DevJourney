import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < input.length(); i++) {
            char c = input.charAt(i);
            if (sb.indexOf(String.valueOf(c)) == -1)
                sb.append(c);
        }
        System.out.println(sb.toString());
    }
}