import java.io.*;
import java.util.Scanner;

class TextAnalyzer {
    public void writeToFile(FileWriter writer, Scanner sc) throws IOException {
        while (true) {
            String line = sc.nextLine();
            if (line.equals("END"))
                break;
            writer.write(line + "\n");
        }
        writer.close();
    }

    public int countWords(BufferedReader reader) throws IOException {
        String line;
        int count = 0;
        while ((line = reader.readLine()) != null) {
            String[] words = line.trim().split("\\s+");
            for (String w : words) {
                if (!w.isEmpty())
                    count++;
            }
        }
        reader.close();
        return count;
    }
}

class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        String filename = "textAnalyze.txt";
        FileWriter writer = new FileWriter(filename);
        TextAnalyzer analyzer = new TextAnalyzer();
        analyzer.writeToFile(writer, sc);
        BufferedReader reader = new BufferedReader(new FileReader(filename));
        int totalWords = analyzer.countWords(reader);
        System.out.println("No of words: " + totalWords);
    }
}