import java.util.Scanner;

class Vehicle {
    double speed;
    double fuelCapacity;

    Vehicle(double speed, double fuelCapacity) {
        this.speed = speed;
        this.fuelCapacity = fuelCapacity;
    }
}

class Car extends Vehicle {
    Car(double speed, double fuelCapacity) {
        super(speed, fuelCapacity);
    }

    double calculateTravelDistance() {
        return speed * fuelCapacity;
    }
}

class Main {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        double speed = scanner.nextDouble();

        double fuelCapacity = scanner.nextDouble();

        Car car = new Car(speed, fuelCapacity);

        System.out.println("Speed: " + String.format("%.2f", car.speed) + " km/h");

        System.out.println("Fuel Capacity: " + String.format("%.2f", car.fuelCapacity)
                + " liters");

        System.out.println("Travel Distance: " + String.format("%.2f",
                car.calculateTravelDistance()) + " km");

        scanner.close();

    }

}