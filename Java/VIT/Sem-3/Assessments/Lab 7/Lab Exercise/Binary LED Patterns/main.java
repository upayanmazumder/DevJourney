import java.util.*;

class BinaryPattern {
    void generatePattern(int n) {
        for (int i = 0; i < n; i++) {
            int val = (i % 2 == 0) ? 1 : 0;
            for (int j = 0; j < n; j++) {
                System.out.print(val + " ");
            }
        }
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        BinaryPattern bp = new BinaryPattern();
        bp.generatePattern(n);
    }
}
