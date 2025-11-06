package Java.Basics.ExceptionHandling;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.StringReader;

public class ThrowsKeywordDemo {

    public static void main(String[] args) {
        try {
            String content = readFirstLine("Line one\nLine two\nLine three");
            System.out.println("First line: " + content);
        } catch (IOException ex) {
            System.out.println("I/O operation failed: " + ex.getMessage());
        }
    }

    private static String readFirstLine(String data) throws IOException {
        try (BufferedReader reader = new BufferedReader(new StringReader(data))) {
            return reader.readLine();
        }
    }
}
