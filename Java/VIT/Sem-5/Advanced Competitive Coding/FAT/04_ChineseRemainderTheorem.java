// Merge congruences using GCD checks and modular inverses, even when moduli share factors.
// Print the least nonnegative solution, or No solution when the constraints conflict.

import java.math.BigInteger;
import java.util.*;

// Generalized CRT: moduli need not be pairwise coprime.
public class Main {

  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int k = s.nextInt();
    if (k <= 0) {
      System.out.println(0);
      return;
    }
    BigInteger A = BigInteger.ZERO, M = BigInteger.ONE;
    for (int i = 0; i < k; i++) {
      BigInteger m = new BigInteger(s.next());
      BigInteger a = new BigInteger(s.next());
      if (m.signum() <= 0) {
        System.out.println("No solution");
        return;
      }
      a = a.mod(m);
      BigInteger diff = a.subtract(A);
      BigInteger g = M.gcd(m);
      if (!diff.mod(g).equals(BigInteger.ZERO)) {
        System.out.println("No solution");
        return;
      }
      // Merge x = A (mod M) with x = a (mod m) using M*t = diff (mod m).
      BigInteger mDiv = m.divide(g);
      BigInteger t = BigInteger.ZERO;
      if (!mDiv.equals(BigInteger.ONE)) {
        BigInteger step = M.divide(g).mod(mDiv);
        t = diff.divide(g).multiply(step.modInverse(mDiv)).mod(mDiv);
      }
      BigInteger newM = M.multiply(mDiv);
      A = A.add(M.multiply(t)).mod(newM);
      M = newM;
    }
    System.out.println(A.mod(M));
  }
}
