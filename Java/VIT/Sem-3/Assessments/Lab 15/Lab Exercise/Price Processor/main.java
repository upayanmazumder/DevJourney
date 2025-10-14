import java.io.*;
import java.util.*;

class PriceProcessor {

    public void writePrices(String fileName) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        FileWriter fw = new FileWriter(fileName);
        for (int i = 0; i < n; i++) {
            double price = sc.nextDouble();
            fw.write(String.format("%.2f", price));
            if (i != n - 1)
                fw.write("\n");
        }
        fw.close();
    }

    public void copyAndDisplayPrices(String sourceFile, String destFile) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(sourceFile));
        FileWriter fw = new FileWriter(destFile);
        String line;
        while ((line = br.readLine()) != null) {
            fw.write(line + "\n");
            System.out.println(line);
        }
        br.close();
        fw.close();
    }
}

class PriceMain {
    public static void main(String[] args) throws IOException {
        PriceProcessor processor = new PriceProcessor();
        String source = "prices.txt";
        String destination = "tax.txt";
        processor.writePrices(source);
        processor.copyAndDisplayPrices(source, destination);
    }
}