import java.util.*;

public class Main {

    public static void main(String[] z) {
        Scanner s = new Scanner(System.in);
        long a = Math.abs(s.nextLong()),
            b = Math.abs(s.nextLong());
        while (b != 0) {
            long t = a % b;
            a = b;
            b = t;
        }
        System.out.println(a);
    }
}
