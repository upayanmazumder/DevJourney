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

        // Process to find leaders
        for (int i = 0; i < n; i++) {
            int sumRight = 0;
            for (int j = i + 1; j < n; j++) {
                sumRight += arr[j];
            }

            if (arr[i] > sumRight) {
                System.out.print(arr[i] + " ");
            }
        }

        scanner.close();
    }
}