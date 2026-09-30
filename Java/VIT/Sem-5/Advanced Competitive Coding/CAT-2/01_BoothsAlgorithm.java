import java.util.*;

public class Main {

    public static void main(String[] z) {
        Scanner s = new Scanner(System.in);
        int m = s.nextInt(),
            q = s.nextInt(),
            M = m,
            A = 0,
            q1 = 0,
            Q = q;
        for (int i = 0; i < 32; i++) {
            if ((Q & 1) == 1 && q1 == 0) A -= M;
            else if ((Q & 1) == 0 && q1 == 1) A += M;
            q1 = Q & 1;
            Q = (Q >>> 1) | (A << 31);
            A >>= 1;
        }
        System.out.println(((long) A << 32) | (Q & 0xffffffffL));
    }
}
