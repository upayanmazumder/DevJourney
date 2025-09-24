import java.util.Scanner;

interface Matrix {
    void diagonalsMinMax(int[][] matrix);
}

class MatrixAnalyzer implements Matrix {
    public void diagonalsMinMax(int[][] matrix) {
        int n = matrix.length;

        int minPrincipal = matrix[0][0];
        int maxPrincipal = matrix[0][0];
        int minSecondary = matrix[0][n - 1];
        int maxSecondary = matrix[0][n - 1];

        for (int i = 0; i < n; i++) {
            if (matrix[i][i] < minPrincipal)
                minPrincipal = matrix[i][i];
            if (matrix[i][i] > maxPrincipal)
                maxPrincipal = matrix[i][i];

            if (matrix[i][n - 1 - i] < minSecondary)
                minSecondary = matrix[i][n - 1 - i];
            if (matrix[i][n - 1 - i] > maxSecondary)
                maxSecondary = matrix[i][n - 1 - i];
        }

        System.out.println("Smallest Element - 1: " + minPrincipal);
        System.out.println("Largest Element - 1: " + maxPrincipal);
        System.out.println("Smallest Element - 2: " + minSecondary);
        System.out.println("Largest Element - 2: " + maxSecondary);
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] matrix = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }

        MatrixAnalyzer analyzer = new MatrixAnalyzer();
        analyzer.diagonalsMinMax(matrix);
        sc.close();
    }
}