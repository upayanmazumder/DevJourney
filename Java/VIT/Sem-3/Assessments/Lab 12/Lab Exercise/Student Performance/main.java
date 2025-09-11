import java.util.*;

abstract class MarksCalculator {
    abstract int calculateSum(int[] marks);

    abstract double calculateAverage(int[] marks);

    abstract int findBestMark(int[] marks);
}

class StudentMarksCalculator extends MarksCalculator {
    @Override
    int calculateSum(int[] marks) {
        int sum = 0;
        for (int m : marks) {
            sum += m;
        }
        return sum;
    }

    @Override
    double calculateAverage(int[] marks) {
        int sum = calculateSum(marks);
        return (double) sum / marks.length;
    }

    @Override
    int findBestMark(int[] marks) {
        int best = marks[0];
        for (int m : marks) {
            if (m > best) {
                best = m;
            }
        }
        return best;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int studentId = scanner.nextInt();
        int numSubjects = scanner.nextInt();
        int[] marks = new int[numSubjects];

        for (int i = 0; i < numSubjects; i++) {
            marks[i] = scanner.nextInt();
        }

        StudentMarksCalculator calculator = new StudentMarksCalculator();

        int total = calculator.calculateSum(marks);
        double average = calculator.calculateAverage(marks);
        int best = calculator.findBestMark(marks);

        System.out.println("Total Marks: " + total);
        System.out.printf("Average Marks: %.2f%n", average);
        System.out.println("Best Mark: " + best);
    }
}