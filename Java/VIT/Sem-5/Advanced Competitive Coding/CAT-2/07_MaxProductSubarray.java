import java.util.*;

public class Main {

    public static void main(String[] z) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        long a = s.nextLong(),
            mx = a,
            mn = a,
            ans = a;
        for (int i = 1; i < n; i++) {
            a = s.nextLong();
            if (a < 0) {
                long t = mx;
                mx = mn;
                mn = t;
            }
            mx = Math.max(a, mx * a);
            mn = Math.min(a, mn * a);
            ans = Math.max(ans, mx);
        }
        System.out.println(ans);
    }
}
