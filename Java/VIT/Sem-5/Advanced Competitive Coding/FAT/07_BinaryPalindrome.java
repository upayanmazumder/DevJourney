// Compare mirrored bits between the lowest bit and the highest set bit.
// A nonnegative number is a binary palindrome when every pair matches, including zero.

import java.util.*;

public class Main {

  public static void main(String[] a) {
    Scanner s = new Scanner(System.in);
    long n = s.nextLong();
    System.out.println(isBinaryPalindrome(n));
  }

  static boolean isBinaryPalindrome(long n) {
    if (n < 0) return false;
    int hi = 63 - Long.numberOfLeadingZeros(n);
    for (int lo = 0; lo < hi; lo++, hi--) if (((n >>> lo) & 1) != ((n >>> hi) & 1)) return false;
    return true;
  }
}
