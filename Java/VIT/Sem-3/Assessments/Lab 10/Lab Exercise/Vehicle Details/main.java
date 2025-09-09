import java.util.Scanner;

class Vehicle {
    double distance;
    double time;

    Vehicle(double distance, double time) {
        this.distance = distance;
        this.time = time;

    }
}

class Car extends Vehicle {
    final String brand;
    private double speed;

    Car(String brand, double distance, double time) {
        super(distance, time);
        this.brand = brand;
    }

    // Calculate speed
    void calc() {
        speed = distance / time;
    }

    // Final display method
    final void display() {
        System.out.println("Brand: " + brand);
        String category;
        if (speed < 20) {
            category = "Slow";
        } else if (speed <= 60) {
            category = "Average";
        } else {
            category = "Fast";
        }
        System.out.printf("Speed: %.2f km/hr (%s)\n", speed, category);
    }

    // Predict distance for a new time
    double predictDistance(double newTime) {
        return speed * newTime;
    }

    // Predict time for a new distance
    double predictTime(double newDistance) {
        return newDistance / speed;
    }
}

class Main {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        double distance = scanner.nextDouble();

        double time = scanner.nextDouble();

        double newTime = scanner.nextDouble();

        double newDistance = scanner.nextDouble();

        Car car = new Car("Toyota", distance, time);

        car.calc();

        car.display();

        System.out.printf("Distance covered in %.1f hours: %.2f km\n", newTime,
                car.predictDistance(newTime));

        System.out.printf("Time taken to cover %.1f km: %.2f hours\n", newDistance,
                car.predictTime(newDistance));

        scanner.close();

    }

}