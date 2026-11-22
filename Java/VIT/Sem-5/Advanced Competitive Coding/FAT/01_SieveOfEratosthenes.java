import java.util.*;

public class Main {

  public static void main(String[] a) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    if (n < 2) {
      System.out.println();
      return;
    }
    boolean[] composite = new boolean[n + 1];
    for (int p = 2; (long) p * p <= n; p++)
      if (!composite[p]) for (long m = (long) p * p; m <= n; m += p) composite[(int) m] = true;
    StringBuilder out = new StringBuilder();
    for (int i = 2; i <= n; i++) if (!composite[i]) out.append(i).append(' ');
    System.out.println(out.toString().trim());
  }
}
