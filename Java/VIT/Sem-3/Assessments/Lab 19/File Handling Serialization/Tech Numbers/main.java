import java.io.*;
import java.util.*;

class Solution {
    public void findTechNumbers(String inputPath, String outputPath) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(inputPath));
        PrintWriter pw = new PrintWriter(new FileWriter(outputPath));

        String line;
        List<String> res = new ArrayList<>();

        while ((line = br.readLine()) != null) {
            line = line.trim();
            if (line.isEmpty()) continue;
            String[] nums = line.split("\\s+");
            for (String s : nums) {
                int num = Integer.parseInt(s);
                String str = String.valueOf(num);
                int len = str.length();
                if (len % 2 != 0) continue;
                int first = Integer.parseInt(str.substring(0, len / 2));
                int second = Integer.parseInt(str.substring(len / 2));
                int sum = first + second;
                if (sum * sum == num) res.add(String.valueOf(num));
            }
        }

        if (res.isEmpty()) {
            pw.print("Empty");
        } else {
            pw.print(String.join(" ", res));
        }

        pw.close();
        br.close();
    }
}

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String numbersLine = br.readLine();
        File numbersFile = File.createTempFile("numbers", ".txt");
        File resultsFile = File.createTempFile("results", ".txt");
        numbersFile.deleteOnExit();
        resultsFile.deleteOnExit();

        FileWriter fw = new FileWriter(numbersFile);
        fw.write(numbersLine);
        fw.close();

        Solution solution = new Solution();
        solution.findTechNumbers(numbersFile.getAbsolutePath(), resultsFile.getAbsolutePath());
    }
}
