import java.io.*;
import java.util.Scanner;

class PasswordStrengthEvaluator {

    public void writePasswordToFile(String password, String fileName) throws IOException {
        FileWriter fw = new FileWriter(fileName);
        fw.write(password);
        fw.close();
    }

    public String readPasswordFromFile(String fileName) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(fileName));
        String password = br.readLine();
        br.close();
        return password;
    }

    public String evaluatePasswordStrength(String password) {
        int len = password.length();
        if (len <= 3)
            return "Weak";
        else if (len >= 4 && len <= 7)
            return "Medium";
        else
            return "Strong";
    }

    public void writeStrengthToFile(String strength, String fileName) throws IOException {
        FileWriter fw = new FileWriter(fileName);
        fw.write(strength);
        fw.close();
    }
}

class PasswordStrengthMain {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String password = scanner.nextLine();
        PasswordStrengthEvaluator evaluator = new PasswordStrengthEvaluator();
        try {
            evaluator.writePasswordToFile(password, "password.txt");
            String storedPassword = evaluator.readPasswordFromFile("password.txt");
            String strength = evaluator.evaluatePasswordStrength(storedPassword);
            evaluator.writeStrengthToFile(strength, "evaluation.txt");
            System.out.println(strength);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}