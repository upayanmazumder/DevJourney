import java.util.*;

public class Main {

    public static void main(String[] z) {
        int x = new Scanner(System.in).nextInt() & 255;
        System.out.println(((x & 15) << 4) | ((x & 240) >>> 4));
    }
}
