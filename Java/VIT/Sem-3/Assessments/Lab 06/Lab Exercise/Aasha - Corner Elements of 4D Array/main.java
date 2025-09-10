import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] arr = new int[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                arr[i][j] = sc.nextInt();
        if (n < 2 || m < 2) {
            System.out.print("The array does not have four corners.");
        } else {
            System.out.print("Top-left: " + arr[0][0] + " ");
            System.out.print("Top-right: " + arr[0][m - 1] + " ");
            System.out.print("Bottom-left: " + arr[n - 1][0] + " ");
            System.out.print("Bottom-right: " + arr[n - 1][m - 1]);
        }
    }
}
