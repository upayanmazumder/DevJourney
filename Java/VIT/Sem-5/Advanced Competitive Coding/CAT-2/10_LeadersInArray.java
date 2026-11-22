// Scan from right to left while tracking the greatest value seen so far.
// Keep values at least that large, then print the leaders in their original order.

import java.util.*;

public class Main {

  public static void main(String[] z) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    int[] a = new int[n], r = new int[n];
    int k = 0, m = Integer.MIN_VALUE;
    for (int i = 0; i < n; i++) a[i] = s.nextInt();
    for (int i = n - 1; i >= 0; i--)
      if (a[i] >= m) {
        r[k++] = a[i];
        m = a[i];
      }
    for (int i = k - 1; i >= 0; i--) System.out.print(r[i] + " ");
  }
}
