import java.io.*;

class FileOperations {

    public void writeBookDetails(String title, String author, String publisher, String filename) throws IOException {
        BufferedWriter bw = new BufferedWriter(new FileWriter(filename));
        bw.write("Title: " + title + "\n");
        bw.write("Author: " + author + "\n");
        bw.write("Publisher: " + publisher + "\n");
        bw.close();

        copyFile("sourcefile.txt", "destinationfile.txt");
    }

    public void copyFile(String source, String destination) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(source));
        BufferedWriter bw = new BufferedWriter(new FileWriter(destination));
        String line;
        while ((line = br.readLine()) != null) {
            bw.write(line + "\n");
        }
        br.close();
        bw.close();
    }

    public void displayFileContent(String filename) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(filename));
        System.out.println("Book Details:");
        String line;
        while ((line = br.readLine()) != null) {
            System.out.println(line);
        }
        br.close();
    }
}
