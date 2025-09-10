import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read number of elements
        int n = scanner.nextInt();
        int[] arr = new int[n];

        // Read array elements
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        // Replace each element with the next greatest element to its right
        for (int i = 0; i < n - 1; i++) {
            int maxRight = arr[i + 1];
            for (int j = i + 2; j < n; j++) {
                if (arr[j] > maxRight) {
                    maxRight = arr[j];
                }
            }
            arr[i] = maxRight;
        }

        // Output the modified array
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }

        scanner.close();
    }
}