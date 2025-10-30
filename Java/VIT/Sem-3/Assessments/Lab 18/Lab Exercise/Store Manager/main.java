import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class ItemType {
    private String name;
    private double deposit;
    private double costPerDay;

    public ItemType(String name, double deposit, double costPerDay) {
        this.name = name;
        this.deposit = deposit;
        this.costPerDay = costPerDay;
    }

    public String getName() {
        return name;
    }

    public double getDeposit() {
        return deposit;
    }

    public double getCostPerDay() {
        return costPerDay;
    }

    @Override
    public String toString() {
        return String.format("%-20s%-20.1f%-20.1f", name, deposit, costPerDay);
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();

        List<ItemType> items = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            String name = sc.nextLine();
            double deposit = sc.nextDouble();
            sc.nextLine();
            double costPerDay = sc.nextDouble();
            if (sc.hasNextLine()) {
                sc.nextLine();
            }
            items.add(new ItemType(name, deposit, costPerDay));
        }

        System.out.format("%-20s%-20s%-20s", "Name", "Deposit", "Cost Per Day");
        System.out.println();
        
        for (ItemType item : items) {
            System.out.println(item);
        }
    }
}