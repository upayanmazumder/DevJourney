import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n1 = sc.nextInt(), n2 = sc.nextInt(), f = 0;
        for (int i = n1; i <= n2; i++) {
            int sum = 0, temp = i, flag = 1;
            while (temp > 0) {
                int d = temp % 10;
                if (d != 0 && i % d == 0) {
                    flag = 0;
                    break;
                }
                sum += d;
                temp /= 10;
            }
            if (flag == 1 && sum != 0 && i % sum == 0) {
                System.out.println(i);
                f = 1;
            }
        }
        if (f == 0)
            System.out.println("No numbers are divisible based on the given conditions.");
    }
}