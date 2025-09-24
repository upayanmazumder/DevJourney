import java.util.Scanner;

class Main {
    static long calculatePermutations(int n) {
        if (n < 0)
            throw new IllegalArgumentException("Error: Negative value of N");
        long result = 1;
        for (int i = 1; i <= n; i++)
            result *= i;
        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        try {
            int n = Integer.parseInt(sc.nextLine());
            System.out.println(calculatePermutations(n));
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
    }
}