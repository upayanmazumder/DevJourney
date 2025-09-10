import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] mat = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mat[i][j] = sc.nextInt();
        boolean isIdentity = true;
        outer: for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if ((i == j && mat[i][j] != 1) || (i != j && mat[i][j] != 0)) {
                    isIdentity = false;
                    break outer;
                }
            }
        if (isIdentity)
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}
