import java.util.*;

class Main {
    static boolean isPrime(int n) {
        if (n < 2)
            return false;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0)
                return false;
        return true;
    }

    static boolean allRightRotationsPrime(String s) {
        int len = s.length();
        for (int i = 0; i < len; i++) {
            System.out.print(s + " ");
            if (!isPrime(Integer.parseInt(s)))
                return false;
            s = s.charAt(s.length() - 1) + s.substring(0, s.length() - 1);
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        System.out.println(allRightRotationsPrime(s));
    }
}