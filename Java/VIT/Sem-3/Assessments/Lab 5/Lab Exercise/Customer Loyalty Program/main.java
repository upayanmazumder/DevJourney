import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        int[] unique = new int[n];
        int count = 0;
        unique[count++] = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[i - 1]) {
                unique[count++] = arr[i];
            }
        }
        for (int i = 0; i < count; i++) {
            System.out.print(unique[i] + " ");
        }
        System.out.println(count);
        scanner.close();
    }
}