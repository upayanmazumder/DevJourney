import java.util.*;

public class Main {

    static void swap(int[] a, int i, int j, int n) {
        while (n-- > 0) {
            int t = a[i];
            a[i++] = a[j];
            a[j++] = t;
        }
    }

    static void rot(int[] a, int d, int n) {
        if (d == 0 || d == n) return;
        int i = d,
            j = n - d;
        while (i != j)
            if (i < j) {
                swap(a, d - i, d + j - i, i);
                j -= i;
            } else {
                swap(a, d - i, d, j);
                i -= j;
            }
        swap(a, d - i, d, i);
    }

    public static void main(String[] z) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt(),
            d = s.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = s.nextInt();
        d %= n;
        rot(a, d, n);
        for (int x : a) System.out.print(x + " ");
    }
}
