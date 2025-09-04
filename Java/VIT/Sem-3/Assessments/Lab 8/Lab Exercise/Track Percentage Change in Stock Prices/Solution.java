import java.util.Scanner;

class Stock {
    private String symbol;
    private double currentPrice;
    private double previousPrice;
    private boolean previousPriceRecorded;

    public Stock(String symbol, double currentPrice) {
        this.symbol = symbol;
        this.currentPrice = currentPrice;
        this.previousPriceRecorded = false;
    }

    public void recordPreviousPrice(double previousPrice) {
        this.previousPrice = previousPrice;
        this.previousPriceRecorded = true;
    }

    public double calculatePercentageChange() {
        if (!previousPriceRecorded) {
            System.out.println("Previous price is not recorded hence cannot calculate percentage change");
            return 0.00;
        }
        if (previousPrice == 0) {
            // Handle division by zero case
            return Double.POSITIVE_INFINITY;
        }
        return ((currentPrice - previousPrice) / previousPrice) * 100;
    }
}

class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String symbol = scanner.next();
        double currentPrice = scanner.nextDouble();
        String recordPrevious = scanner.next();

        Stock stock = new Stock(symbol, currentPrice);

        if (recordPrevious.equalsIgnoreCase("yes")) {
            double previousPrice = scanner.nextDouble();
            stock.recordPreviousPrice(previousPrice);
        }

        double percentageChange = stock.calculatePercentageChange();
        System.out.printf("%.2f%%", percentageChange);
        scanner.close();
    }
}

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String symbol = scanner.next();
        double currentPrice = scanner.nextDouble();
        Stock stock = new Stock(symbol, currentPrice);
        String recordPrevious = scanner.next();
        if (recordPrevious.equalsIgnoreCase("yes")) {
            double previousPrice = scanner.nextDouble();
            stock.recordPreviousPrice(previousPrice);
        }
    }
}
