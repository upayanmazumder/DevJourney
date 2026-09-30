import java.util.*;

public class Main {

    public static void main(String[] z) {
        int x = new Scanner(System.in).nextInt(),
            best = 0,
            cur = 0,
            prev = 0;
        for (int i = 0; i < 32; i++) {
            if ((x & 1) == 1) cur++;
            else {
                prev = cur;
                cur = 0;
            }
            best = Math.max(best, prev + cur + 1);
            x >>>= 1;
        }
        System.out.println(Math.min(best, 32));
    }
}
