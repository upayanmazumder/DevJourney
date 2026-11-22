// Fill mirrored positions recursively with valid strobogrammatic digit pairs.
// Skip outer leading zeros and use only 0, 1, or 8 at the center.

import java.util.*;

public class Main {
  static final char[][] PAIRS = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};

  public static void main(String[] a) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    if (n <= 0) {
      System.out.println();
      return;
    }
    StringBuilder out = new StringBuilder();
    build(0, new char[n], out);
    System.out.println(out.toString().trim());
  }

  static void build(int i, char[] cur, StringBuilder out) {
    int j = cur.length - 1 - i;
    if (i > j) {
      out.append(cur).append(' ');
      return;
    }
    if (i == j) {
      for (char c : new char[] {'0', '1', '8'}) {
        cur[i] = c;
        out.append(cur).append(' ');
      }
      return;
    }
    for (char[] p : PAIRS) {
      if (i == 0 && p[0] == '0') continue; // no leading zero
      cur[i] = p[0];
      cur[j] = p[1];
      build(i + 1, cur, out);
    }
  }
}
