// Track the largest and smallest products ending at each array position.
// Negative values can exchange their roles, so both are needed for the maximum product.

import java.math.BigInteger;
import java.util.*;

public class Main {

  public static void main(String[] z) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    if (n <= 0) {
      System.out.println(0);
      return;
    }
    BigInteger a = BigInteger.valueOf(s.nextLong());
    BigInteger mx = a, mn = a, ans = a;
    for (int i = 1; i < n; i++) {
      a = BigInteger.valueOf(s.nextLong());
      if (a.signum() < 0) {
        BigInteger t = mx;
        mx = mn;
        mn = t;
      }
      mx = a.max(mx.multiply(a));
      mn = a.min(mn.multiply(a));
      ans = ans.max(mx);
    }
    System.out.println(ans);
  }
}
