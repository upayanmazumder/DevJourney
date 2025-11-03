import java.io.*;
import java.util.*;

class PerfectSquareFinder {
    public void findPerfectSquares(String inputPath, String outputPath) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(inputPath));
        PrintWriter pw = new PrintWriter(new FileWriter(outputPath));
        List<Integer> squares = new ArrayList<>();
        String line;

        while ((line = br.readLine()) != null) {
            line = line.trim();
            if (line.isEmpty()) continue;
            String[] nums = line.split("\\s+");
            for (String s : nums) {
                int num = Integer.parseInt(s);
                int root = (int) Math.sqrt(num);
                if (root * root == num) squares.add(num);
            }
        }

        if (squares.isEmpty()) {
            pw.print("No perfect squares found");
            System.out.print("No perfect squares found");
        } else {
            for (int val : squares) {
                pw.println(val);
                System.out.println(val);
            }
        }

        pw.close();
        br.close();
    }
}

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
        int[] numbers = new int[n];
        String[] inputNumbers = br.readLine().trim().split("\\s+");
        for (int i = 0; i < n; i++) {
            numbers[i] = Integer.parseInt(inputNumbers[i]);
        }

        File inputFile = File.createTempFile("integers", ".txt");
        File outputFile = File.createTempFile("perfect_squares", ".txt");
        inputFile.deleteOnExit();
        outputFile.deleteOnExit();

        PrintWriter pw = new PrintWriter(new FileWriter(inputFile));
        for (int i = 0; i < n; i++) {
            pw.print(numbers[i]);
            if (i < n - 1) pw.print(" ");
        }
        pw.close();

        PerfectSquareFinder finder = new PerfectSquareFinder();
        finder.findPerfectSquares(inputFile.getAbsolutePath(), outputFile.getAbsolutePath());
    }
}
