import java.util.*;

class MessageAnalyzer {
    public void analyzeMessageFrequency(List<String> lines) {
        TreeMap<Character, Integer> charFrequencies = new TreeMap<>();
        for (String line : lines) {
            for (char c : line.toCharArray()) {
                if (Character.isLetter(c)) {
                    charFrequencies.put(c, charFrequencies.getOrDefault(c, 0) + 1);
                }
            }
        }
        System.out.println("Character Frequency:");
        for (Map.Entry<Character, Integer> entry : charFrequencies.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<String> lines = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            lines.add(sc.nextLine());
        }
        MessageAnalyzer analyzer = new MessageAnalyzer();
        analyzer.analyzeMessageFrequency(lines);
    }
}