import java.util.Scanner;

abstract class Vehicle {
    protected int rentalRate;

    public Vehicle(int rentalRate) {
        this.rentalRate = rentalRate;
    }

    abstract int calculateRentalCost(int days);

    public void displayInfo() {
        System.out.println("Rental Rate: " + rentalRate + " per day");
    }
}

class Car extends Vehicle {
    public Car(int rentalRate) {
        super(rentalRate);
    }

    @Override
    int calculateRentalCost(int days) {
        return rentalRate * days;
    }
}

class Bike extends Vehicle {
    public Bike(int rentalRate) {
        super(rentalRate);
    }

    @Override
    int calculateRentalCost(int days) {
        return rentalRate * days;
    }
}

class Truck extends Vehicle {
    public Truck(int rentalRate) {
        super(rentalRate);
    }

    @Override
    int calculateRentalCost(int days) {
        return rentalRate * days;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int carRate = input.nextInt();
        int bikeRate = input.nextInt();
        int truckRate = input.nextInt();
        int rentalDays = input.nextInt();

        Car car = new Car(carRate);
        Bike bike = new Bike(bikeRate);
        Truck truck = new Truck(truckRate);

        car.displayInfo();
        System.out.println("Total Rental Cost for Car: " + car.calculateRentalCost(rentalDays));

        bike.displayInfo();
        System.out.println("Total Rental Cost for Bike: " + bike.calculateRentalCost(rentalDays));

        truck.displayInfo();
        System.out.println("Total Rental Cost for Truck: " + truck.calculateRentalCost(rentalDays));

        input.close();
    }
}