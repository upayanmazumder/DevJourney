// Manacher reuses mirrored palindrome radii to find the longest substring in linear time.
// Integer sentinels prevent input collisions, and equal-length ties keep the leftmost result.

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

  // Integer sentinels cannot collide with any UTF-16 code unit, so no input
  // character can be mistaken for a separator or boundary.
  static final int SEP = -1;
  static final int LEFT = -2;
  static final int RIGHT = -3;

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String s = br.readLine();
    if (s == null) s = "";

    int n = s.length();
    if (n == 0) {
      System.out.println();
      return;
    }

    int[] t = new int[2 * n + 3];
    t[0] = LEFT;
    t[2 * n + 2] = RIGHT;
    for (int i = 0; i < n; i++) {
      t[2 * i + 1] = SEP;
      t[2 * i + 2] = s.charAt(i);
    }
    t[2 * n + 1] = SEP;

    int[] p = new int[t.length];
    int center = 0, right = 0;
    for (int i = 1; i < t.length - 1; i++) {
      int mirror = 2 * center - i;
      if (i < right) p[i] = Math.min(right - i, p[mirror]);
      while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) p[i]++;
      if (i + p[i] > right) {
        center = i;
        right = i + p[i];
      }
    }

    int bestLen = 0, bestCenter = 0;
    for (int i = 1; i < t.length - 1; i++) {
      if (p[i] > bestLen) {
        bestLen = p[i];
        bestCenter = i;
      }
    }

    int start = (bestCenter - bestLen) / 2;
    System.out.println(s.substring(start, start + bestLen));
  }
}
