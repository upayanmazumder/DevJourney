import java.util.*;

public class Main {
  static final int BLOCK = 1 << 20;

  public static void main(String[] a) {
    Scanner s = new Scanner(System.in);
    int l = s.nextInt(), h = s.nextInt();
    if (h < 2 || l > h) {
      System.out.println();
      return;
    }
    if (l < 2) l = 2;

    // Base primes up to floor(sqrt(h)).
    int lim = (int) Math.sqrt(h);
    while ((long) (lim + 1) * (lim + 1) <= h) lim++;
    while ((long) lim * lim > h) lim--;
    boolean[] composite = new boolean[lim + 1];
    List<Integer> primes = new ArrayList<>();
    for (int i = 2; i <= lim; i++)
      if (!composite[i]) {
        primes.add(i);
        for (long j = (long) i * i; j <= lim; j += i) composite[(int) j] = true;
      }

    StringBuilder out = new StringBuilder();
    for (long lo = l; lo <= h; lo += BLOCK) {
      long hi = Math.min((long) h, lo + BLOCK - 1);
      boolean[] marked = new boolean[(int) (hi - lo + 1)];
      for (int p : primes) {
        long start = Math.max((long) p * p, ((lo + p - 1) / p) * (long) p);
        for (long j = start; j <= hi; j += p) marked[(int) (j - lo)] = true;
      }
      for (long i = lo; i <= hi; i++) if (!marked[(int) (i - lo)]) out.append(i).append(' ');
    }
    System.out.println(out.toString().trim());
  }
}
