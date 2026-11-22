// Each grid cell receives the paths from the cell above and the cell to its left.
// Store one row of exact counts to count all down/right paths to the destination.

import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    if (!sc.hasNextInt()) return;

    int rows = sc.nextInt();
    int cols = sc.nextInt();
    if (rows <= 0 || cols <= 0) return;

    // One row of the DP table: dp[c] = number of paths to the current cell.
    BigInteger[] dp = new BigInteger[cols];
    Arrays.fill(dp, BigInteger.ONE);

    for (int r = 1; r < rows; r++) {
      for (int c = 1; c < cols; c++) {
        dp[c] = dp[c].add(dp[c - 1]);
      }
    }

    System.out.println(dp[cols - 1]);
  }
}
