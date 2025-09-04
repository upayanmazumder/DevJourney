import java.util.*;

class PowerPascalPattern {
    void generatePattern(int n) {
        int[][] arr = new int[n][n];
        for (int i = 0; i < n; i++) {
            arr[i][0] = 1;
            for (int j = 1; j < n; j++) {
                int top = (i > 0) ? arr[i - 1][j] : 0;
                int left = arr[i][j - 1];
                arr[i][j] = top + left;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(arr[i][j] + " ");
            }
        }
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        PowerPascalPattern p = new PowerPascalPattern();
        p.generatePattern(n);
    }
}
