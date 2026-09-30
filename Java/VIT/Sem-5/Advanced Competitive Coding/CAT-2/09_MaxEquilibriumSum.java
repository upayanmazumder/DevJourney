import java.util.*;

public class Main {

    public static void main(String[] z) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        long[] a = new long[n];
        long r = 0,
            l = 0,
            ans = Long.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            a[i] = s.nextLong();
            r += a[i];
        }
        for (long x : a) {
            r -= x;
            if (l == r) ans = Math.max(ans, l);
            l += x;
        }
        System.out.println(ans == Long.MIN_VALUE ? 0 : ans);
    }
}
