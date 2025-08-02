import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] matrix = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                matrix[i][j] = sc.nextInt();
        int mainSum = 0;
        int secondarySum = 0;
        for (int i = 0; i < n; i++) {
            mainSum += matrix[i][i];
            secondarySum += matrix[i][n - 1 - i];
        }
        System.out.print("Sum of the main diagonal: " + mainSum + " ");
        System.out.println("Sum of the secondary diagonal: " + secondarySum);
    }
}