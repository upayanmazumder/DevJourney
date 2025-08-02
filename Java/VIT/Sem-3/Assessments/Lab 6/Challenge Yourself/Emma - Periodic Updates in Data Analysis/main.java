import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt(), c = sc.nextInt();
        int[][] mat = new int[r][c];
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                mat[i][j] = sc.nextInt();
        int insertType = sc.nextInt(), insertIndex = sc.nextInt();
        if (insertType == 0) {
            int[][] newMat = new int[r + 1][c];
            for (int i = 0; i < insertIndex; i++)
                newMat[i] = mat[i];
            for (int j = 0; j < c; j++)
                newMat[insertIndex][j] = sc.nextInt();
            for (int i = insertIndex; i < r; i++)
                newMat[i + 1] = mat[i];
            mat = newMat;
            r++;
        } else {
            int[][] newMat = new int[r][c + 1];
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < insertIndex; j++)
                    newMat[i][j] = mat[i][j];
                newMat[i][insertIndex] = sc.nextInt();
                for (int j = insertIndex; j < c; j++)
                    newMat[i][j + 1] = mat[i][j];
            }
            mat = newMat;
            c++;
        }
        System.out.println("After insertion");
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                System.out.print(mat[i][j] + " ");
            System.out.println();
        }
        int deleteType = sc.nextInt(), deleteIndex = sc.nextInt();
        if (deleteType == 0) {
            int[][] newMat = new int[r - 1][c];
            for (int i = 0, ni = 0; i < r; i++)
                if (i != deleteIndex)
                    newMat[ni++] = mat[i];
            mat = newMat;
            r--;
        } else {
            int[][] newMat = new int[r][c - 1];
            for (int i = 0; i < r; i++) {
                for (int j = 0, nj = 0; j < c; j++)
                    if (j != deleteIndex)
                        newMat[i][nj++] = mat[i][j];
            }
            mat = newMat;
            c--;
        }
        System.out.println("After deletion");
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                System.out.print(mat[i][j] + " ");
            System.out.println();
        }
    }
}
