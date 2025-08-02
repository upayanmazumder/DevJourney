import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt();
        int c = sc.nextInt();
        int[][] mat = new int[r][c];
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                mat[i][j] = sc.nextInt();
        int maxSum = 0;
        int maxRow = 0;
        for (int i = 0; i < r; i++) {
            int sum = 0;
            for (int j = 0; j < c; j++)
                sum += mat[i][j];
            if (sum > maxSum) {
                maxSum = sum;
                maxRow = i;
            }
        }
        for (int i = 0; i < r; i++) {
            if (i == maxRow)
                continue;
            for (int j = 0; j < c; j++)
                System.out.print(mat[i][j] + " ");
            System.out.println();
        }
    }
}