// Booth multiplication uses adjacent multiplier bits to select addition or subtraction.
// Arithmetic shifts combine the accumulator and multiplier into the signed product.

import java.util.*;

public class Main {

  public static void main(String[] z) {
    Scanner s = new Scanner(System.in);
    long m = s.nextInt(), q = s.nextInt();
    long M = m, A = 0, Q = q & 0xffffffffL;
    int q1 = 0;
    for (int i = 0; i < 32; i++) {
      if ((Q & 1) == 1 && q1 == 0) A -= M;
      else if ((Q & 1) == 0 && q1 == 1) A += M;
      q1 = (int) (Q & 1);
      Q = (Q >>> 1) | ((A & 1) << 31);
      A >>= 1;
    }
    System.out.println((A << 32) | (Q & 0xffffffffL));
  }
}
