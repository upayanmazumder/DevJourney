import java.io.*;
import java.util.*;

class InventoryManager {
    public void calculateStockValue(String inputPath, String outputPath) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(inputPath));
        PrintWriter writer = new PrintWriter(new FileWriter(outputPath));
        double total = 0.0;
        String line;
        while ((line = br.readLine()) != null) {
            line = line.trim();
            if (line.isEmpty()) continue;
            String[] parts = line.split("\\s+");
            String name = parts[0];
            double price = Double.parseDouble(parts[1]);
            int qty = Integer.parseInt(parts[2]);
            double value = price * qty;
            total += value;
            writer.println(name + ": Rs." + String.format("%.1f", value));
        }
        writer.println("Total Stock Value: Rs." + String.format("%.1f", total));
        writer.close();
        br.close();
    }
}

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int numberOfProducts = Integer.parseInt(br.readLine().trim());
        StringBuilder inventoryDataBuilder = new StringBuilder();
        for (int i = 0; i < numberOfProducts; i++) {
            inventoryDataBuilder.append(br.readLine()).append("\n");
        }
        File inputFile = File.createTempFile("inventory", ".txt");
        FileWriter fw = new FileWriter(inputFile);
        fw.write(inventoryDataBuilder.toString());
        fw.close();

        File outputFile = File.createTempFile("stock_value", ".txt");
        InventoryManager manager = new InventoryManager();
        manager.calculateStockValue(inputFile.getAbsolutePath(), outputFile.getAbsolutePath());

        try (BufferedReader reader = new BufferedReader(new FileReader(outputFile))) {
            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
        }
    }
}
