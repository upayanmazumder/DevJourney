// Compare digit runs by numeric value without parsing them into fixed-width integers.
// Break equal-value ties by leading-zero count and compare other characters normally.

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

  static boolean isDigit(char c) {
    return c >= '0' && c <= '9';
  }

  // Natural order: digit runs compare by numeric value, without parsing into a
  // number (so arbitrarily long runs cannot overflow). If two runs have the same
  // numeric value, the run with fewer leading zeros comes first.
  static int compareNatural(String a, String b) {
    int i = 0, j = 0;
    int n = a.length(), m = b.length();

    while (i < n && j < m) {
      char ca = a.charAt(i), cb = b.charAt(j);

      if (isDigit(ca) && isDigit(cb)) {
        int startA = i, startB = j;
        while (i < n && isDigit(a.charAt(i))) i++;
        while (j < m && isDigit(b.charAt(j))) j++;

        int p = startA, q = startB;
        while (p < i - 1 && a.charAt(p) == '0') p++;
        while (q < j - 1 && b.charAt(q) == '0') q++;

        int lenA = i - p, lenB = j - q;
        if (lenA != lenB) return lenA < lenB ? -1 : 1;
        for (int k = 0; k < lenA; k++) {
          char da = a.charAt(p + k), db = b.charAt(q + k);
          if (da != db) return da < db ? -1 : 1;
        }

        int zerosA = p - startA, zerosB = q - startB;
        if (zerosA != zerosB) return zerosA < zerosB ? -1 : 1;
        continue;
      }

      if (ca != cb) return ca < cb ? -1 : 1;
      i++;
      j++;
    }

    return Integer.compare(n - i, m - j);
  }

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String first = br.readLine();
    if (first == null) return;

    int n = Integer.parseInt(first.trim());
    List<String> items = new ArrayList<>();
    for (int k = 0; k < n; k++) {
      String line = br.readLine();
      if (line == null) break;
      items.add(line);
    }

    items.sort(Main::compareNatural);

    StringBuilder out = new StringBuilder();
    for (String s : items) out.append(s).append('\n');
    System.out.print(out);
  }
}
