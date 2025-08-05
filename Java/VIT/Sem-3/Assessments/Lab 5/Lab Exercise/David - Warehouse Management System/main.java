import java.util.Scanner;
import java.util.ArrayList;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read initial number of product IDs
        int n = scanner.nextInt();
        int[] original = new int[n];

        // Read the initial product IDs
        for (int i = 0; i < n; i++) {
            original[i] = scanner.nextInt();
        }

        // Read insertion index and product to insert
        int indexA = scanner.nextInt();
        int productA = scanner.nextInt();

        // Read deletion index
        int indexD = scanner.nextInt();

        // --- Addition Operation ---
        ArrayList<Integer> addedList = new ArrayList<>();
        for (int i = 0; i < n + 1; i++) {
            if (i == indexA) {
                addedList.add(productA);
            }
            if (i < n) {
                addedList.add(original[i]);
            }
        }

        // Print array after addition
        for (int val : addedList) {
            System.out.print(val + " ");
        }
        System.out.println();

        // --- Deletion Operation ---
        for (int i = 0; i < n; i++) {
            if (i != indexD) {
                System.out.print(original[i] + " ");
            }
        }

        scanner.close();
    }
}