import java.util.Scanner;

class CircleUtils {
    // Method to calculate circumference for integer radius
    public double calculateCircumference(int radius) {
        return 2 * 3.14 * radius;
    }

    // Method to calculate circumference for double radius
    public double calculateCircumference(double radius) {
        return 2 * 3.14 * radius;
    }

    // Method to calculate area for integer radius
    public double calculateArea(int radius) {
        return 3.14 * radius * radius;
    }

    // Method to calculate area for double radius
    public double calculateArea(double radius) {
        return 3.14 * radius * radius;
    }
}

class Main {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int radiusInt = scanner.nextInt();

        double radiusDouble = scanner.nextDouble();

        CircleUtils circleUtils = new CircleUtils();

        double circumferenceInt = circleUtils.calculateCircumference(radiusInt);

        double circumferenceDouble = circleUtils.calculateCircumference(radiusDouble);

        double areaInt = circleUtils.calculateArea(radiusInt);

        double areaDouble = circleUtils.calculateArea(radiusDouble);

        System.out.format("%.2f %.2f\n", circumferenceInt, circumferenceDouble);

        System.out.format("%.2f %.2f", areaInt, areaDouble);

        scanner.close();

    }

}
