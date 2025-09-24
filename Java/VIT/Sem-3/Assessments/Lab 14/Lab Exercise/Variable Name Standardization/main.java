import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String sentence = sc.nextLine().trim();
        String[] words = sentence.split(" ");
        StringBuilder camelCase = new StringBuilder();

        for (int i = 0; i < words.length; i++) {
            if (words[i].isEmpty())
                continue;
            if (i == 0) {
                camelCase.append(words[i].toLowerCase());
            } else {
                camelCase.append(Character.toUpperCase(words[i].charAt(0)));
                if (words[i].length() > 1) {
                    camelCase.append(words[i].substring(1).toLowerCase());
                }
            }
        }

        System.out.println(camelCase.toString());
    }
}