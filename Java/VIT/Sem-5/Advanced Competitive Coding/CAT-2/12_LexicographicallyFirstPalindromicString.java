// Count Unicode code points and reject inputs with more than one odd frequency.
// Build the smallest ordered half, add the odd center, and mirror the half.

import java.util.*;

public class Main {

  public static void main(String[] z) {
    String s = new Scanner(System.in).next();
    Map<Integer, Integer> c = new TreeMap<>();
    for (int cp : s.codePoints().toArray()) c.merge(cp, 1, Integer::sum);
    int odd = 0, mid = 0;
    List<Integer> half = new ArrayList<>();
    for (Map.Entry<Integer, Integer> e : c.entrySet()) {
      if ((e.getValue() & 1) == 1) {
        odd++;
        mid = e.getKey();
      }
      for (int i = 0; i < e.getValue() / 2; i++) half.add(e.getKey());
    }
    if (odd > 1) {
      System.out.println("Not possible");
      return;
    }
    StringBuilder left = new StringBuilder(), right = new StringBuilder();
    for (int cp : half) left.appendCodePoint(cp);
    for (int i = half.size() - 1; i >= 0; i--) right.appendCodePoint(half.get(i));
    if (odd == 1) left.appendCodePoint(mid);
    System.out.println(left.append(right));
  }
}
