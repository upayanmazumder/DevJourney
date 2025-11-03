import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String message = sc.nextLine();
        sc.close();
        StringBuilder encrypted = new StringBuilder();
        for (char ch : message.toCharArray()) encrypted.append((char)(ch + 1));
        System.out.println("Encrypted Message: " + encrypted);
        try (FileWriter writer = new FileWriter("encrypted_data.txt")) {
            writer.write(encrypted.toString());
        } catch (IOException e) {
            return;
        }
        StringBuilder encryptedData = new StringBuilder();
        try (BufferedReader reader = new BufferedReader(new FileReader("encrypted_data.txt"))) {
            String line;
            while ((line = reader.readLine()) != null) encryptedData.append(line);
        } catch (IOException e) {
            return;
        }
        StringBuilder decrypted = new StringBuilder();
        for (char ch : encryptedData.toString().toCharArray()) decrypted.append((char)(ch - 1));
        System.out.println("Decrypted Message: " + decrypted);
    }
}
