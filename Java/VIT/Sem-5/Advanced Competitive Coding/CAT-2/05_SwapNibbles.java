// Mask the low eight bits, then shift the two four-bit nibbles in opposite directions.
// Combine them with bitwise OR to exchange the upper and lower nibbles.

import java.util.*;

public class Main {

  public static void main(String[] z) {
    int x = new Scanner(System.in).nextInt() & 255;
    System.out.println(((x & 15) << 4) | ((x & 240) >>> 4));
  }
}
