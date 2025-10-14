import java.io.*;
import java.util.Scanner;

class SentimentAnalyzer {

    public String getUserInput() {
        Scanner sc = new Scanner(System.in);
        return sc.nextLine();
    }

    public void writeInputToFile(String sentence, String fileName) throws IOException {
        FileOutputStream fos = new FileOutputStream(fileName);
        DataOutputStream dos = new DataOutputStream(fos);
        dos.writeBytes(sentence);
        dos.close();
    }

    public String analyzeSentiment(String fileName) throws IOException {
        FileInputStream fis = new FileInputStream(fileName);
        DataInputStream dis = new DataInputStream(fis);
        StringBuilder sb = new StringBuilder();
        while (dis.available() > 0) {
            sb.append((char) dis.read());
        }
        dis.close();

        String content = sb.toString().toLowerCase();

        if (content.contains("happy") || content.contains("good") ||
                content.contains("excellent") || content.contains("positive")) {
            return "Positive";
        } else if (content.contains("sad") || content.contains("bad") ||
                content.contains("terrible") || content.contains("negative")) {
            return "Negative";
        } else {
            return "Neutral";
        }
    }

    public void writeDataToFile(String sentiment, String fileName) throws IOException {
        FileOutputStream fos = new FileOutputStream(fileName);
        DataOutputStream dos = new DataOutputStream(fos);
        dos.writeBytes(sentiment);
        dos.close();
    }

    public void displayResult(String fileName) throws IOException {
        FileInputStream fis = new FileInputStream(fileName);
        DataInputStream dis = new DataInputStream(fis);
        StringBuilder sb = new StringBuilder();
        while (dis.available() > 0) {
            sb.append((char) dis.read());
        }
        dis.close();
        System.out.println(sb.toString());
    }

}

class Main {
    public static void main(String[] args) {
        try {
            SentimentAnalyzer sentimentAnalyzer = new SentimentAnalyzer();
            String sentence = sentimentAnalyzer.getUserInput();
            sentimentAnalyzer.writeDataToFile(sentence, "input.txt");
            String sentiment = sentimentAnalyzer.analyzeSentiment("input.txt");
            sentimentAnalyzer.writeDataToFile(sentiment, "output.txt");
            sentimentAnalyzer.displayResult("output.txt");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}