import java.io.*;

class FileHandlingMaster {

    // --- TEXT WRITING USING FILEWRITER ---
    static void writeTextFile(String filename) {
        try (FileWriter fw = new FileWriter(filename)) {
            fw.write("Hello World!\n");
            fw.write("This is a file handling demo.\n");
            fw.write("Line 3: Java rocks!\n");
            System.out.println("✅ FileWriter: Wrote data to " + filename);
        } catch (IOException e) {
            System.out.println("⚠ Error writing with FileWriter: " + e.getMessage());
        }
    }

    // --- TEXT READING USING FILEREADER ---
    static void readTextFile(String filename) {
        try (FileReader fr = new FileReader(filename)) {
            int ch;
            System.out.println("\n📖 Reading file char-by-char:");
            while ((ch = fr.read()) != -1) {
                System.out.print((char) ch);
            }
            System.out.println();
        } catch (IOException e) {
            System.out.println("⚠ Error reading with FileReader: " + e.getMessage());
        }
    }

    // --- BUFFERED READING AND WRITING ---
    static void bufferedCopy(String source, String dest) {
        try (BufferedReader br = new BufferedReader(new FileReader(source));
             BufferedWriter bw = new BufferedWriter(new FileWriter(dest))) {

            String line;
            while ((line = br.readLine()) != null) {
                bw.write(line.toUpperCase()); // Example of transformation
                bw.newLine();
            }
            System.out.println("✅ BufferedReader/Writer: Copied " + source + " → " + dest);

        } catch (IOException e) {
            System.out.println("⚠ Buffered I/O error: " + e.getMessage());
        }
    }

    // --- BINARY FILE WRITING USING DATAOUTPUTSTREAM ---
    static void writeBinaryData(String filename) {
        try (DataOutputStream dos = new DataOutputStream(new FileOutputStream(filename))) {
            dos.writeInt(123);
            dos.writeDouble(45.67);
            dos.writeUTF("Java I/O FTW!");
            System.out.println("✅ DataOutputStream: Wrote binary data to " + filename);
        } catch (IOException e) {
            System.out.println("⚠ Error writing binary file: " + e.getMessage());
        }
    }

    // --- BINARY FILE READING USING DATAINPUTSTREAM ---
    static void readBinaryData(String filename) {
        try (DataInputStream dis = new DataInputStream(new FileInputStream(filename))) {
            int num = dis.readInt();
            double val = dis.readDouble();
            String text = dis.readUTF();
            System.out.println("\n📦 DataInputStream: Read binary data:");
            System.out.println("Integer: " + num);
            System.out.println("Double: " + val);
            System.out.println("String: " + text);
        } catch (IOException e) {
            System.out.println("⚠ Error reading binary file: " + e.getMessage());
        }
    }

    // --- STRING MANIPULATION & FILE PROCESSING ---
    static void processTextFile(String input, String output) {
        try (BufferedReader br = new BufferedReader(new FileReader(input));
             BufferedWriter bw = new BufferedWriter(new FileWriter(output))) {

            String line;
            int totalWords = 0;
            while ((line = br.readLine()) != null) {
                String[] words = line.trim().split("\\s+");
                for (String w : words) {
                    if (!w.isEmpty()) totalWords++;
                }
                // Replace vowels as transformation
                String modified = line.replaceAll("[AEIOUaeiou]", "x");
                bw.write(modified);
                bw.newLine();
            }

            System.out.println("✅ Processed " + input + " → " + output);
            System.out.println("🧮 Total words counted: " + totalWords);

        } catch (IOException e) {
            System.out.println("⚠ Error processing file: " + e.getMessage());
        }
    }

    // --- FILE EXISTENCE CHECK & PATH DEMO ---
    static void fileInfo(String filename) {
        File f = new File(filename);
        System.out.println("\n📁 File Info:");
        System.out.println("Path: " + f.getAbsolutePath());
        System.out.println("Exists? " + f.exists());
        System.out.println("Size: " + (f.exists() ? f.length() + " bytes" : "N/A"));
    }

    public static void main(String[] args) {
        String textFile = "sample.txt";
        String copiedFile = "copy.txt";
        String binaryFile = "data.bin";
        String processedFile = "processed.txt";

        // TEXT HANDLING
        writeTextFile(textFile);
        readTextFile(textFile);
        bufferedCopy(textFile, copiedFile);

        // BINARY HANDLING
        writeBinaryData(binaryFile);
        readBinaryData(binaryFile);

        // STRING MANIPULATION & PROCESSING
        processTextFile(textFile, processedFile);

        // FILE INFO
        fileInfo(textFile);
        fileInfo(binaryFile);

        System.out.println("\n🚀 All File I/O operations completed successfully!");
    }
}
