import java.util.Scanner;

class Appliance {
    private double wattage;
    private double hours;

    public void setDetails(double wattage, double hours) {
        this.wattage = wattage;
        this.hours = hours;
    }

    public double calculateDailyConsumption() {
        return (wattage * hours) / 1000.0;
    }

    public double calculateMonthlyConsumption() {
        return calculateDailyConsumption() * 30;
    }
}
