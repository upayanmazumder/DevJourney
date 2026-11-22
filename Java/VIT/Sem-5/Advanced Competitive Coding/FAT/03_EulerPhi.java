import java.util.*;

public class Main {

  public static void main(String[] a) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    System.out.println(n <= 0 ? 0 : phi(n));
  }

  static int phi(int n) {
    int result = n;
    for (int p = 2; (long) p * p <= n; p++)
      if (n % p == 0) {
        while (n % p == 0) n /= p;
        result -= result / p;
      }
    if (n > 1) result -= result / n;
    return result;
  }
}
