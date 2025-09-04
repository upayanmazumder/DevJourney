import java.util.Scanner;
import java.lang.Math;

class PythagoreanCalculator {
    public boolean isPythagoreanTriple(int a, int b, int c) {
        // Calculate squares of the sides to avoid potential overflow with very large
        // numbers,
        // though with the given constraints (1-100) it's not a major concern.
        long a2 = (long) a * a;
        long b2 = (long) b * b;
        long c2 = (long) c * c;

        // Check all three possible combinations to see if any form a Pythagorean
        // triple.
        // The condition for a Pythagorean triple is that the square of the longest side
        // is equal to the sum of the squares of the other two sides.
        if (a2 + b2 == c2 || a2 + c2 == b2 || b2 + c2 == a2) {
            return true;
        } else {
            return false;
        }
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        PythagoreanCalculator calculator = new PythagoreanCalculator();
        boolean result = calculator.isPythagoreanTriple(a, b, c);
    }
}
