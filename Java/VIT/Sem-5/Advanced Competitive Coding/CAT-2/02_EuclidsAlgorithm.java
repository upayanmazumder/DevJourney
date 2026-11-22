import java.math.BigInteger;
import java.util.*;

public class Main {

  public static void main(String[] z) {
    Scanner s = new Scanner(System.in);
    BigInteger a = BigInteger.valueOf(s.nextLong()).abs();
    BigInteger b = BigInteger.valueOf(s.nextLong()).abs();
    while (b.signum() != 0) {
      BigInteger t = a.remainder(b);
      a = b;
      b = t;
    }
    System.out.println(a);
  }
}
