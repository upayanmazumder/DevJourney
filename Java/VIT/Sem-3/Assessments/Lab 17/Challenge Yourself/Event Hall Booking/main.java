import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

class Hall implements Comparable<Hall> {
    private String name;
    private String contactNumber;
    private double costPerDay;
    private String ownerName;

    public Hall(String name, String contactNumber, double costPerDay, String ownerName) {
        this.name = name;
        this.contactNumber = contactNumber;
        this.costPerDay = costPerDay;
        this.ownerName = ownerName;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getContactNumber() {
        return contactNumber;
    }

    public void setContactNumber(String contactNumber) {
        this.contactNumber = contactNumber;
    }

    public double getCostPerDay() {
        return costPerDay;
    }

    public void setCostPerDay(double costPerDay) {
        this.costPerDay = costPerDay;
    }

    public String getOwnerName() {
        return ownerName;
    }

    public void setOwnerName(String ownerName) {
        this.ownerName = ownerName;
    }

    @Override
    public int compareTo(Hall other) {
        return Double.compare(this.costPerDay, other.costPerDay);
    }

    @Override
    public String toString() {
        return String.format("%s %s %.1f %s", name, contactNumber, costPerDay, ownerName);
    }
}

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        scanner.nextLine();

        ArrayList<Hall> halls = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            String name = scanner.nextLine();
            String contactNumber = scanner.nextLine();
            double costPerDay = scanner.nextDouble();
            scanner.nextLine();
            String ownerName = scanner.nextLine();

            halls.add(new Hall(name, contactNumber, costPerDay, ownerName));
        }

        scanner.close();

        Collections.sort(halls);

        for (Hall hall : halls) {
            System.out.println(hall.toString());
        }
    }
}