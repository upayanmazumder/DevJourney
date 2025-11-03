import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String text = sc.nextLine();
        char cons = sc.next().charAt(0);
        sc.close();
        try (FileWriter fw = new FileWriter("file1.txt")) {
            fw.write(text);
        } catch (IOException e) {
            return;
        }
        StringBuilder modified = new StringBuilder();
        try (BufferedReader br = new BufferedReader(new FileReader("file1.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                for (char ch : line.toCharArray()) {
                    if ("AEIOUaeiou".indexOf(ch) != -1) modified.append(cons);
                    else modified.append(ch);
                }
            }
        } catch (IOException e) {
            return;
        }
        try (FileWriter fw = new FileWriter("file2.txt")) {
            fw.write(modified.toString());
        } catch (IOException e) {
            return;
        }
        StringBuilder output = new StringBuilder();
        try (BufferedReader br = new BufferedReader(new FileReader("file2.txt"))) {
            String line;
            while ((line = br.readLine()) != null) output.append(line);
        } catch (IOException e) {
            return;
        }
        System.out.println(output);
    }
}
