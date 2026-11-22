// Place one queen per row while excluding occupied columns and both diagonal directions.
// Undo each choice after recursion to print every valid board, or No solution.

import java.util.Scanner;

public class Main {

  static int n;
  static int[] queenColumn;
  static boolean[] usedColumn;
  static boolean[] usedDownDiagonal; // row + col
  static boolean[] usedUpDiagonal; // row - col + n - 1
  static StringBuilder out = new StringBuilder();
  static int solutions = 0;

  static void place(int row) {
    if (row == n) {
      solutions++;
      if (solutions > 1) out.append('\n');
      printBoard();
      return;
    }

    for (int col = 0; col < n; col++) {
      int down = row + col;
      int up = row - col + n - 1;
      if (usedColumn[col] || usedDownDiagonal[down] || usedUpDiagonal[up]) continue;

      queenColumn[row] = col;
      usedColumn[col] = usedDownDiagonal[down] = usedUpDiagonal[up] = true;
      place(row + 1);
      usedColumn[col] = usedDownDiagonal[down] = usedUpDiagonal[up] = false;
    }
  }

  static void printBoard() {
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < n; c++) {
        if (c > 0) out.append(' ');
        out.append(c == queenColumn[r] ? '1' : '0');
      }
      out.append('\n');
    }
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    if (!sc.hasNextInt()) return;

    n = sc.nextInt();
    if (n <= 0) {
      System.out.println("No solution");
      return;
    }

    queenColumn = new int[n];
    usedColumn = new boolean[n];
    usedDownDiagonal = new boolean[2 * n - 1];
    usedUpDiagonal = new boolean[2 * n - 1];

    place(0);

    if (solutions == 0) System.out.println("No solution");
    else System.out.print(out);
  }
}
