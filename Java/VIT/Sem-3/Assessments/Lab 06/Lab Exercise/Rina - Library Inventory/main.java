import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt();
        int c = sc.nextInt();
        int[][] matrix = new int[r][c];
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                matrix[i][j] = sc.nextInt();
        for (int i = 0; i < r; i++) {
            int sum = 0;
            for (int j = 0; j < c; j++)
                sum += matrix[i][j];
            for (int j = 0; j < c; j++)
                matrix[i][j] = sum;
        }
        System.out.print("Transformed matrix: ");
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                System.out.print(matrix[i][j] + " ");
        int mr = sc.nextInt();
        int mc = sc.nextInt();
        int[][] second = new int[mr][mc];
        for (int i = 0; i < mr; i++)
            for (int j = 0; j < mc; j++)
                second[i][j] = sc.nextInt();
        int mergeType = sc.nextInt();
        System.out.print("Final merged matrix: ");
        if (mergeType == 0) {
            for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++)
                    System.out.print(matrix[i][j] + " ");
            for (int i = 0; i < mr; i++)
                for (int j = 0; j < mc; j++)
                    System.out.print(second[i][j] + " ");
        } else {
            for (int i = 0; i < Math.max(r, mr); i++) {
                for (int j = 0; j < c; j++) {
                    if (i < r)
                        System.out.print(matrix[i][j] + " ");
                    else
                        System.out.print("0 ");
                }
                for (int j = 0; j < mc; j++) {
                    if (i < mr)
                        System.out.print(second[i][j] + " ");
                    else
                        System.out.print("0 ");
                }
            }
        }
    }
}