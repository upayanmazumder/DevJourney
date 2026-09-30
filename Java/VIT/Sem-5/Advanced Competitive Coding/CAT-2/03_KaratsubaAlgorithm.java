import java.util.*;

public class Main {

    static long k(long x, long y) {
        if (x < 10 || y < 10) return x * y;
        int n = Math.max(d(x), d(y)),
            m = n / 2;
        long p = (long) Math.pow(10, m),
            a = x / p,
            b = x % p,
            c = y / p,
            e = y % p;
        long ac = k(a, c),
            bd = k(b, e),
            adbc = k(a + b, c + e) - ac - bd;
        return ac * p * p + adbc * p + bd;
    }

    static int d(long x) {
        return Long.toString(Math.abs(x)).length();
    }

    public static void main(String[] z) {
        Scanner s = new Scanner(System.in);
        System.out.println(k(s.nextLong(), s.nextLong()));
    }
}
