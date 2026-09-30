import java.util.*;

public class Main {

    public static void main(String[] z) {
        String s = new Scanner(System.in).next();
        int[] c = new int[256];
        for (char x : s.toCharArray()) c[x]++;
        int odd = 0;
        char mid = 0;
        for (int i = 0; i < 256; i++) if ((c[i] & 1) == 1) {
            odd++;
            mid = (char) i;
        }
        if (odd > 1) {
            System.out.println("Not possible");
            return;
        }
        StringBuilder a = new StringBuilder(),
            b = new StringBuilder();
        for (int i = 0; i < 256; i++) for (
            int j = 0;
            j < c[i] / 2;
            j++
        ) a.append((char) i);
        b.append(a).reverse();
        System.out.println(a + (odd == 1 ? "" + mid : "") + b);
    }
}
