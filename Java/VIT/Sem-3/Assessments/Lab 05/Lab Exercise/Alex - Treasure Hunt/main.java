import java.util.Scanner;
import java.util.Arrays;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        Arrays.sort(arr);
        int sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum += arr[i];
        }
        System.out.println("Maximum Sum: " + sum);
        scanner.close();
    }
}