import java.io.*;
import java.util.*;

class Solution {
    private boolean isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    public void findPrimes(String inputPath, String outputPath) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(inputPath));
        PrintWriter pw = new PrintWriter(new FileWriter(outputPath));
        List<Integer> primes = new ArrayList<>();
        String line;

        while ((line = br.readLine()) != null) {
            line = line.trim();
            if (line.isEmpty()) continue;
            String[] nums = line.split("\\s+");
            for (String s : nums) {
                int num = Integer.parseInt(s);
                if (isPrime(num)) primes.add(num);
            }
        }

        if (primes.isEmpty()) {
            pw.print("No primes found");
        } else {
            for (int i = 0; i < primes.size(); i++) {
                pw.print(primes.get(i));
                if (i < primes.size() - 1) pw.print(" ");
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
        String numbersLine = br.readLine().trim();

        
        File inputFile = new File("numbers.txt");
        FileWriter fw = new FileWriter(inputFile);
        fw.write(numbersLine);
        fw.close();
        
        File outputFile = new File("primes_result.txt");
        
        Solution sol = new Solution();
        sol.findPrimes(inputFile.getAbsolutePath(), outputFile.getAbsolutePath());
        
        BufferedReader out = new BufferedReader(new FileReader(outputFile));
        System.out.print(out.readLine());
        out.close();
    }
}
