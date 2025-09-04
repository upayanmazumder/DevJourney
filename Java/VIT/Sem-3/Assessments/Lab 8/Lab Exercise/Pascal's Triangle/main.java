import java.util.Scanner;

class PascalTriangle {
    public void printPascalRow(int n) {
        if (n <= 0) {
            System.out.println("Invalid Input");
            return;
        }

        long current = 1;
        System.out.print(current + " ");

        for (int i = 1; i < n; i++) {
            current = current * (n - i) / i;
            System.out.print(current + (i == n - 1 ? "" : " "));
        }
    }
}

class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int rowNumber = scanner.nextInt();

        PascalTriangle pascalTriangle = new PascalTriangle();

        if (rowNumber < 0) {
            System.out.println("Invalid Input");
            return;
        }

        pascalTriangle.printPascalRow(rowNumber);
        scanner.close();
    }
}

class Main {
    public static void main(String[] args) {
        PascalTriangle pascalTriangle = new PascalTriangle();
        Scanner scanner = new Scanner(System.in);
        int rowNumber = scanner.nextInt();
        if (rowNumber < 0) {
            System.out.println("Invalid Input");
            return;
        }

        pascalTriangle.printPascalRow(rowNumber);
    }
}
