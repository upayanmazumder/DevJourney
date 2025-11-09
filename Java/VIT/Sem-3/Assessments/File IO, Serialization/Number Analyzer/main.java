import java.io.*;
import java.util.*;

class NumberAnalyzer {
    public void findNumbersGreaterThanReverse(String inputPath, String outputPath) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(inputPath));
        PrintWriter pw = new PrintWriter(new FileWriter(outputPath));

        List<String> res = new ArrayList<>();
        String line;
        while ((line = br.readLine()) != null) {
            line = line.trim();
            if (line.isEmpty()) continue;
            int num = Integer.parseInt(line);
            int rev = 0, temp = num;
            while (temp > 0) {
                rev = rev * 10 + (temp % 10);
                temp /= 10;
            }
            if (num > rev) res.add(String.valueOf(num));
        }

        if (res.isEmpty()) pw.print("No numbers found");
        else pw.print(String.join(" ", res));

        pw.close();
        br.close();
    }
}

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringBuilder inputData = new StringBuilder();
        String[] numbers = br.readLine().split(" ");
        for (String num : numbers) inputData.append(num).append("\n");

        File inputFile = File.createTempFile("input", ".txt");
        FileWriter fw = new FileWriter(inputFile);
        fw.write(inputData.toString());
        fw.close();

        File outputFile = File.createTempFile("output", ".txt");
        NumberAnalyzer analyzer = new NumberAnalyzer();
        analyzer.findNumbersGreaterThanReverse(inputFile.getAbsolutePath(), outputFile.getAbsolutePath());

        try (BufferedReader reader = new BufferedReader(new FileReader(outputFile))) {
            String result = reader.readLine();
            if (result != null) System.out.println(result);
        }
    }
}
