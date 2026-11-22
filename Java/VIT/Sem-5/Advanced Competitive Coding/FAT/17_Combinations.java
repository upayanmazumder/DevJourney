import java.util.Scanner;

public class Main {

  static int[] values;
  static int[] chosen;
  static StringBuilder out = new StringBuilder();

  // Choices are made by position, so input order is preserved in each output.
  static void combine(int start, int depth, int r) {
    if (depth == r) {
      for (int i = 0; i < r; i++) {
        if (i > 0) out.append(' ');
        out.append(values[chosen[i]]);
      }
      out.append('\n');
      return;
    }

    for (int i = start; i <= values.length - (r - depth); i++) {
      chosen[depth] = i;
      combine(i + 1, depth + 1, r);
    }
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    if (!sc.hasNextInt()) return;

    int n = sc.nextInt();
    values = new int[n];
    for (int i = 0; i < n; i++) values[i] = sc.nextInt();

    int r = sc.nextInt();
    if (r < 0 || r > n) return;

    chosen = new int[r];
    combine(0, 0, r);
    System.out.print(out);
  }
}
