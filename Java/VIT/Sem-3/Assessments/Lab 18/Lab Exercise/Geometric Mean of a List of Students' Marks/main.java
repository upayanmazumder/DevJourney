import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Locale;

class MathUtility {
    public double calculateGeometricMean(List<Double> marks) {
        if (marks == null || marks.isEmpty()) {
            return 0.0;
        }
        int n = marks.size();
        double product = 1.0;
        for (double mark : marks) {
            if (mark <= 0.0) {
                return 0.0;
            }
            product *= mark;
        }
        double geometricMean = Math.pow(product, 1.0 / n);
        return geometricMean;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in).useLocale(Locale.US);
        List<Double> numbersList = new ArrayList<>();
        MathUtility utility = new MathUtility();
        int n = input.nextInt();
        for (int i = 0; i < n; i++) {
            numbersList.add(input.nextDouble());
        }
        double geometricMean = utility.calculateGeometricMean(numbersList);
        System.out.printf("Geometric mean of the list: %.2f%n", geometricMean);
        input.close();
    }
}