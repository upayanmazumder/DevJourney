import java.math.BigInteger;
import java.util.*;

public class Main {

  static BigInteger k(BigInteger x, BigInteger y) {
    if (x.compareTo(BigInteger.TEN) < 0 || y.compareTo(BigInteger.TEN) < 0) return x.multiply(y);
    int n = Math.max(x.toString().length(), y.toString().length()), m = n / 2;
    BigInteger p = BigInteger.TEN.pow(m);
    BigInteger[] xs = x.divideAndRemainder(p), ys = y.divideAndRemainder(p);
    BigInteger a = xs[0], b = xs[1], c = ys[0], e = ys[1];
    BigInteger ac = k(a, c), bd = k(b, e);
    BigInteger adbc = k(a.add(b), c.add(e)).subtract(ac).subtract(bd);
    return ac.multiply(p).multiply(p).add(adbc.multiply(p)).add(bd);
  }

  public static void main(String[] z) {
    Scanner s = new Scanner(System.in);
    BigInteger x = BigInteger.valueOf(s.nextLong()), y = BigInteger.valueOf(s.nextLong());
    BigInteger p = k(x.abs(), y.abs());
    System.out.println(x.signum() * y.signum() < 0 ? p.negate() : p);
  }
}
