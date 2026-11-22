// Compare digits from opposite ends using their 180-degree rotation partners.
// Only 0, 1, 8, and the paired digits 6 and 9 can pass the check.

import java.util.*;

public class Main {

  public static void main(String[] a) {
    Scanner s = new Scanner(System.in);
    String n = s.next();
    System.out.println(isStrobogrammatic(n));
  }

  static boolean isStrobogrammatic(String s) {
    int i = 0, j = s.length() - 1;
    while (i <= j) {
      char l = s.charAt(i), r = s.charAt(j);
      boolean ok =
          (l == '0' && r == '0')
              || (l == '1' && r == '1')
              || (l == '8' && r == '8')
              || (l == '6' && r == '9')
              || (l == '9' && r == '6');
      if (!ok) return false;
      i++;
      j--;
    }
    return true;
  }
}
