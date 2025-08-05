import java.util.Scanner;
import java.util.HashSet;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        HashSet<Integer> seen = new HashSet<>();
        boolean found = false;
        for (int i = 0; i < n; i++) {
            if (seen.contains(arr[i])) {
                System.out.println(arr[i]);
                found = true;
                break;
            } else {
                seen.add(arr[i]);
            }
        }
        if (!found) {
            System.out.println("No repeated element found in the array");
        }
        scanner.close();
    }
}