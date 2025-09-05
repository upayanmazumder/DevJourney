import java.util.Scanner;

class GCD {
    // Method to find GCD using Euclidean Algorithm
    public int findGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Method to find LCM using formula: (a * b) / gcd
    public int findLCM(int a, int b) {
        return (a * b) / findGCD(a, b);
    }
}
