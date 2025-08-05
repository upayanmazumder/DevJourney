import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();
        int minSum = Integer.MAX_VALUE;
        int a = 0, b = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum = arr[i] + arr[j];
                if (Math.abs(sum) < Math.abs(minSum) ||
                        (Math.abs(sum) == Math.abs(minSum) && i < a)) {
                    minSum = sum;
                    a = i;
                    b = j;
                }
            }
        }
        System.out.println("Pair with the sum closest to zero: " + arr[a] + " and " + arr[b]);
    }
}
