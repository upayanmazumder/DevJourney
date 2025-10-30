import java.util.ArrayList;
import java.util.Scanner;

class VowelFilter {
    public static void filterWords(int n, Scanner sc) {
        ArrayList<String> originalWords = new ArrayList<>();
        ArrayList<String> filteredWords = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            originalWords.add(sc.nextLine());
        }

        for (String word : originalWords) {
            int vowelCount = 0;
            String lowerCaseWord = word.toLowerCase();

            for (char c : lowerCaseWord.toCharArray()) {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    vowelCount++;
                }
            }

            if (vowelCount <= 2) {
                filteredWords.add(word);
            }
        }

        for (String word : filteredWords) {
            System.out.println(word);
        }
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); 
        sc.nextLine(); 
        VowelFilter.filterWords(n, sc);
        sc.close();
    }
}