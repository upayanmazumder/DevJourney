import java.util.Scanner;

class VolumeCalculator {
    double calculateVolume(double side) {
        return side * side * side;
    }

    double calculateVolume(double base, double height) {
        return (base * height) / 3.0;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice = scanner.nextInt();
        VolumeCalculator calculator = new VolumeCalculator();
        if (choice == 1) {
            double side = scanner.nextDouble();
            double volume = calculator.calculateVolume(side);
            System.out.printf("Volume of the cube: %.2f\n", volume);
        } else if (choice == 2) {
            double base = scanner.nextDouble();
            double height = scanner.nextDouble();
            double volume = calculator.calculateVolume(base, height);
            System.out.printf("Volume of the pyramid: %.2f\n", volume);
        } else {
            System.out.println("Invalid");
        }
    }
}