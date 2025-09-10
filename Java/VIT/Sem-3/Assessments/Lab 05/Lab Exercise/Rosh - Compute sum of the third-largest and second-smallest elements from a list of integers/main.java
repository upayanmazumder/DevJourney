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
        int secondSmallest = arr[1];
        int thirdLargest = arr[n - 3];
        System.out.println(secondSmallest + thirdLargest);
        scanner.close();
    }
}