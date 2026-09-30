import java.util.*;

public class Main {

    public static void main(String[] z) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt(),
            cand = 0,
            c = 0;
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = s.nextInt();
            if (c == 0) {
                cand = a[i];
                c = 1;
            } else if (a[i] == cand) c++;
            else c--;
        }
        c = 0;
        for (int x : a) if (x == cand) c++;
        System.out.println(c > n / 2 ? cand : -1);
    }
}
