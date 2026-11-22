import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

  static boolean nextPermutation(char[] a) {
    int i = a.length - 2;
    while (i >= 0 && a[i] >= a[i + 1]) i--;
    if (i < 0) return false;

    int j = a.length - 1;
    while (a[j] <= a[i]) j--;

    char t = a[i];
    a[i] = a[j];
    a[j] = t;

    for (int l = i + 1, r = a.length - 1; l < r; l++, r--) {
      t = a[l];
      a[l] = a[r];
      a[r] = t;
    }
    return true;
  }

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String line = br.readLine();
    if (line == null) line = "";

    char[] a = line.toCharArray();
    Arrays.sort(a);

    StringBuilder out = new StringBuilder();
    do {
      out.append(a).append('\n');
    } while (nextPermutation(a));

    System.out.print(out);
  }
}
