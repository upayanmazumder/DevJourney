import java.io.*;
import java.util.Scanner;

public class FileHandlingDemo {

    // 1. Write text to a file
    static void writeFile(String filename, String content) {
        try (FileWriter fw = new FileWriter(filename)) {
            fw.write(content);
            System.out.println("File written successfully.");
        } catch (IOException e) {
            System.err.println("Error writing file: " + e.getMessage());
        }
    }

    // 2. Read file using BufferedReader
    static void readFileBuffered(String filename) {
        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            String line;
            System.out.println("\nReading with BufferedReader:");
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            System.err.println("Error reading file: " + e.getMessage());
        }
    }

    // 3. Read file using Scanner
    static void readFileScanner(String filename) {
        try (Scanner sc = new Scanner(new File(filename))) {
            System.out.println("\nReading with Scanner:");
            while (sc.hasNextLine()) {
                System.out.println(sc.nextLine());
            }
        } catch (FileNotFoundException e) {
            System.err.println("File not found: " + e.getMessage());
        }
    }

    // 4. Display file information
    static void showFileInfo(String filename) {
        File f = new File(filename);
        if (f.exists()) {
            System.out.println("\nFile Information:");
            System.out.println("Name: " + f.getName());
            System.out.println("Path: " + f.getAbsolutePath());
            System.out.println("Size: " + f.length() + " bytes");
            System.out.println("Readable: " + f.canRead());
            System.out.println("Writable: " + f.canWrite());
        } else {
            System.out.println("File not found.");
        }
    }

    // 5. Delete file
    static void deleteFile(String filename) {
        File f = new File(filename);
        if (f.exists()) {
            if (f.delete()) {
                System.out.println("\nFile deleted successfully.");
            } else {
                System.out.println("\nFailed to delete file.");
            }
        } else {
            System.out.println("\nFile does not exist.");
        }
    }

    // Main method
    public static void main(String[] args) {
        String filename = "demo.txt";
        String content = """
                Hello, this is a Java File Handling demonstration.
                This program writes, reads, inspects, and deletes files.
                """;

        writeFile(filename, content);
        readFileBuffered(filename);
        readFileScanner(filename);
        showFileInfo(filename);
        deleteFile(filename);
    }
}
