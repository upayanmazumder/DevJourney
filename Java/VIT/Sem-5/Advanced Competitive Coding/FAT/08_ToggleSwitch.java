import java.util.*;

public class Main {

  public static void main(String[] a) {
    Scanner s = new Scanner(System.in);
    long n = s.nextLong();
    System.out.println(n <= 0 ? 0 : isqrt(n));
  }

  // Exact floor square root without floating point.
  static long isqrt(long n) {
    if (n < 2) return n;
    long lo = 1, hi = 3037000499L; // floor(sqrt(Long.MAX_VALUE))
    while (lo < hi) {
      long mid = lo + (hi - lo + 1) / 2;
      if (mid <= n / mid) lo = mid;
      else hi = mid - 1;
    }
    return lo;
  }
}
