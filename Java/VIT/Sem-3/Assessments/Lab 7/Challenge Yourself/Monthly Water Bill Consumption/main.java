import java.util.Scanner;

class WaterBill {
    private String consumerName;
    private String areaType;
    private int unitsUsed;
    private double totalBill;
    private final double serviceCharge = 50.0;
    private boolean validArea = true;

    public void getInput() {
        Scanner sc = new Scanner(System.in);
        consumerName = sc.nextLine();
        areaType = sc.nextLine();
        unitsUsed = sc.nextInt();
    }

    public void calculateBill() {
        totalBill = serviceCharge;

        if (areaType.equalsIgnoreCase("Urban")) {
            if (unitsUsed <= 100) {
                totalBill += unitsUsed * 2;
            } else {
                totalBill += unitsUsed * 3;
            }
        } else if (areaType.equalsIgnoreCase("Rural")) {
            if (unitsUsed <= 100) {
                totalBill += unitsUsed * 1.5;
            } else {
                totalBill += unitsUsed * 2.5;
            }
        } else {
            validArea = false;
        }
    }

    public void displayBill() {
        if (!validArea) {
            System.out.println("Invalid area type entered.");
        }
        System.out.println(totalBill);
    }
}

class Main {
    public static void main(String[] args) {
        WaterBill bill = new WaterBill();
        bill.getInput();
        bill.calculateBill();
        bill.displayBill();
    }
}
