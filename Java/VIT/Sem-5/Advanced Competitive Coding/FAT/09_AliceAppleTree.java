import java.math.BigInteger;
import java.util.*;

public class Main {

  public static void main(String[] a) {
    Scanner s = new Scanner(System.in);
    long needed = s.nextLong();
    if (needed <= 0) {
      System.out.println(0);
      return;
    }
    BigInteger target = BigInteger.valueOf(needed);
    long hi = 1;
    while (apples(hi).compareTo(target) < 0) hi <<= 1;
    long lo = 0;
    while (lo < hi) {
      long mid = lo + (hi - lo) / 2;
      if (apples(mid).compareTo(target) >= 0) hi = mid;
      else lo = mid + 1;
    }
    System.out.println(BigInteger.valueOf(lo).multiply(BigInteger.valueOf(8)));
  }

  // Total apples inside rings 1..r: 2*r*(r+1)*(2r+1).
  static BigInteger apples(long r) {
    BigInteger b = BigInteger.valueOf(r);
    return b.multiply(b.add(BigInteger.ONE))
        .multiply(b.shiftLeft(1).add(BigInteger.ONE))
        .shiftLeft(1);
  }
}
