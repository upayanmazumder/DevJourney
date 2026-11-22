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
    BigInteger[] a = new BigInteger[n];
    BigInteger r = BigInteger.ZERO, l = BigInteger.ZERO, ans = null;
    for (int i = 0; i < n; i++) {
      a[i] = BigInteger.valueOf(s.nextLong());
      r = r.add(a[i]);
    }
    for (BigInteger x : a) {
      r = r.subtract(x);
      if (l.equals(r) && (ans == null || l.compareTo(ans) > 0)) ans = l;
      l = l.add(x);
    }
    System.out.println(ans == null ? "0" : ans.toString());
  }
}
