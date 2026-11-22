// Search open maze cells by trying a downward move before a rightward move.
// Mark the path, undo failed choices, and print one solution or No solution.

import java.util.Scanner;

public class Main {

  static int n;
  static int[][] maze;
  static int[][] solution;

  static boolean solve(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= n) return false;
    if (maze[r][c] == 0 || solution[r][c] == 1) return false;

    solution[r][c] = 1;
    if (r == n - 1 && c == n - 1) return true;

    if (solve(r + 1, c)) return true; // move down
    if (solve(r, c + 1)) return true; // move right

    solution[r][c] = 0; // backtrack
    return false;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    if (!sc.hasNextInt()) return;

    n = sc.nextInt();
    if (n <= 0) {
      System.out.println("No solution");
      return;
    }

    maze = new int[n][n];
    solution = new int[n][n];
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < n; c++) maze[r][c] = sc.nextInt();
    }

    if (!solve(0, 0)) {
      System.out.println("No solution");
      return;
    }

    StringBuilder out = new StringBuilder();
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < n; c++) {
        if (c > 0) out.append(' ');
        out.append(solution[r][c]);
      }
      out.append('\n');
    }
    System.out.print(out);
  }
}
