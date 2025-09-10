import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        int maxProd = arr[0], currMax = arr[0], currMin = arr[0];
        for (int i = 1; i < n; i++) {
            int tempMax = Math.max(arr[i], Math.max(currMax * arr[i], currMin * arr[i]));
            currMin = Math.min(arr[i], Math.min(currMax * arr[i], currMin * arr[i]));
            currMax = tempMax;
            maxProd = Math.max(maxProd, currMax);
        }
        System.out.println(maxProd);
        scanner.close();
    }
}