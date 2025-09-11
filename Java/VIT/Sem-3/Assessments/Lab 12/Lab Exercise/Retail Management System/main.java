import java.util.Scanner;

abstract class Product {
    protected double cost;
    protected double price;

    public Product(double cost, double price) {
        this.cost = cost;
        this.price = price;
    }

    abstract double calculateTotalCost();

    abstract double calculateProfitMargin();
}

class ElectronicsProduct extends Product {
    private double warrantyCost;

    public ElectronicsProduct(double cost, double price, double warrantyCost) {
        super(cost, price);
        this.warrantyCost = warrantyCost;
    }

    @Override
    double calculateTotalCost() {
        return cost + warrantyCost;
    }

    @Override
    double calculateProfitMargin() {
        return ((price - cost) / price) * 100;
    }
}

class ClothingProduct extends Product {
    private double materialCost;

    public ClothingProduct(double cost, double price, double materialCost) {
        super(cost, price);
        this.materialCost = materialCost;
    }

    @Override
    double calculateTotalCost() {
        return cost + materialCost;
    }

    @Override
    double calculateProfitMargin() {
        return ((price - cost) / price) * 100;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        double eCost = scanner.nextDouble();
        double ePrice = scanner.nextDouble();
        double warrantyCost = scanner.nextDouble();

        double cCost = scanner.nextDouble();
        double cPrice = scanner.nextDouble();
        double materialCost = scanner.nextDouble();

        ElectronicsProduct electronicsProduct = new ElectronicsProduct(eCost, ePrice, warrantyCost);
        ClothingProduct clothingProduct = new ClothingProduct(cCost, cPrice, materialCost);

        System.out.println("Electronics Product:");
        System.out.printf("Total Cost: %.2f\n", electronicsProduct.calculateTotalCost());
        System.out.printf("Profit Margin: %.2f\n", electronicsProduct.calculateProfitMargin());

        System.out.println();
        System.out.println("Clothing Product:");
        System.out.printf("Total Cost: %.2f\n", clothingProduct.calculateTotalCost());
        System.out.printf("Profit Margin: %.2f\n", clothingProduct.calculateProfitMargin());

        scanner.close();
    }
}