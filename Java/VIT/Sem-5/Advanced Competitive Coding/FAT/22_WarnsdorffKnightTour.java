// Move the knight to the unvisited square with the fewest onward moves.
// Warnsdorff is a greedy heuristic, so No tour found does not prove impossibility.

import java.util.Scanner;

public class Main {

  static final int[] DR = {2, 1, -1, -2, -2, -1, 1, 2};
  static final int[] DC = {1, 2, 2, 1, -1, -2, -2, -1};

  static int n;
  static int[][] board;

  static boolean inside(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < n;
  }

  // Number of unvisited squares a knight could still move to from (r, c).
  static int onwardDegree(int r, int c) {
    int count = 0;
    for (int k = 0; k < 8; k++) {
      int nr = r + DR[k], nc = c + DC[k];
      if (inside(nr, nc) && board[nr][nc] == 0) count++;
    }
    return count;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    if (!sc.hasNextInt()) return;

    n = sc.nextInt();
    int startRow = sc.nextInt();
    int startCol = sc.nextInt();

    if (!inside(startRow, startCol)) {
      System.out.println("No tour found");
      return;
    }

    board = new int[n][n];
    int r = startRow, c = startCol;
    board[r][c] = 1; // the starting square is move 1

    int step = 2;
    while (step <= n * n) {
      int bestRow = -1, bestCol = -1, bestDegree = Integer.MAX_VALUE;

      for (int k = 0; k < 8; k++) {
        int nr = r + DR[k], nc = c + DC[k];
        if (!inside(nr, nc) || board[nr][nc] != 0) continue;

        int degree = onwardDegree(nr, nc);
        if (degree < bestDegree) {
          bestDegree = degree;
          bestRow = nr;
          bestCol = nc;
        }
      }

      if (bestRow == -1) break; // Warnsdorff's heuristic got stuck

      r = bestRow;
      c = bestCol;
      board[r][c] = step++;
    }

    if (step <= n * n) {
      System.out.println("No tour found");
      return;
    }

    StringBuilder out = new StringBuilder();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (j > 0) out.append(' ');
        out.append(board[i][j]);
      }
      out.append('\n');
    }
    System.out.print(out);
  }
}
