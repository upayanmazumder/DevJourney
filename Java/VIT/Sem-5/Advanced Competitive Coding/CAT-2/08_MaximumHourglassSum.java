// Visit every 3-by-3 window in the 6-by-6 matrix and sum its seven hourglass cells.
// Keep the largest sum, using long arithmetic to avoid overflow for integer cells.

import java.util.*;

public class Main {

  public static void main(String[] z) {
    Scanner s = new Scanner(System.in);
    int[][] a = new int[6][6];
    for (int i = 0; i < 6; i++) for (int j = 0; j < 6; j++) a[i][j] = s.nextInt();
    long ans = Long.MIN_VALUE;
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++) {
        long x =
            (long) a[i][j]
                + a[i][j + 1]
                + a[i][j + 2]
                + a[i + 1][j + 1]
                + a[i + 2][j]
                + a[i + 2][j + 1]
                + a[i + 2][j + 2];
        ans = Math.max(ans, x);
      }
    System.out.println(ans);
  }
}
