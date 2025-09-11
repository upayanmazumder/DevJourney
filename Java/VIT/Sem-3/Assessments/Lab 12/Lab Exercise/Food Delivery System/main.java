import java.util.Scanner;

interface Delivery {
    double getBaseDeliveryFee();
}

interface ChargeCalculator extends Delivery {
    double calculateDistanceCharge(int distance);

    double calculateWeightSurcharge(int weight);

    double calculateTotalCharge();
}

class ZomatoDelivery implements ChargeCalculator {
    private int distance;
    private int weight;
    private double baseFee;

    public ZomatoDelivery(int distance, int weight, double baseFee) {
        this.distance = distance;
        this.weight = weight;
        this.baseFee = baseFee;
    }

    @Override
    public double getBaseDeliveryFee() {
        return baseFee;
    }

    @Override
    public double calculateDistanceCharge(int distance) {
        double charge = 0.0;
        if (distance <= 5) {
            charge = distance * 3.0;
        } else if (distance <= 15) {
            charge = (5 * 2.0) + ((distance - 5) * 1.5);
        } else {
            charge = (5 * 2.0) + (10 * 1.5) + ((distance - 15) * 1.0);
        }
        return charge;
    }

    @Override
    public double calculateWeightSurcharge(int weight) {
        if (weight > 5) {
            return 4.0;
        }
        return 0.0;
    }

    @Override
    public double calculateTotalCharge() {
        return getBaseDeliveryFee() + calculateDistanceCharge(distance) + calculateWeightSurcharge(weight);
    }
}

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int distance = scanner.nextInt();
        int weight = scanner.nextInt();
        double baseFee = scanner.nextDouble();

        ZomatoDelivery delivery = new ZomatoDelivery(distance, weight, baseFee);

        System.out.printf("Base Delivery Fee: %.1f\n", delivery.getBaseDeliveryFee());
        System.out.printf("Distance Charge: %.1f\n", delivery.calculateDistanceCharge(distance));
        System.out.printf("Weight Surcharge: %.1f\n", delivery.calculateWeightSurcharge(weight));
        System.out.printf("Total Delivery Charge: %.1f\n", delivery.calculateTotalCharge());

        scanner.close();
    }
}