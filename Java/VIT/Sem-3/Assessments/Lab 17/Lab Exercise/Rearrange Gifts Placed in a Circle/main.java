import java.util.Scanner;
import java.util.Arrays;

class GiftExchanger {

    public static <T> boolean swapElements(T[] array, int a, int b) {
        if (a < 0 || a >= array.length || b < 0 || b >= array.length) {
            return false;
        }

        T temp = array[a];
        array[a] = array[b];
        array[b] = temp;
        return true;
    }

    public static <T> String arrayToString(T[] array) {
        StringBuilder sb = new StringBuilder("[");
        for (int i = 0; i < array.length; i++) {
            sb.append(array[i]);
            if (i < array.length - 1) {
                sb.append(", ");
            }
        }
        sb.append("]");
        return sb.toString();
    }
}

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        Integer[] gifts = new Integer[n];

        for (int i = 0; i < n; i++) {
            gifts[i] = scanner.nextInt();
        }

        int a = scanner.nextInt();
        int b = scanner.nextInt();

        scanner.close();

        Integer[] originalGifts = Arrays.copyOf(gifts, n);

        System.out.println("Original Array: " + GiftExchanger.arrayToString(originalGifts));

        boolean swapped = GiftExchanger.swapElements(gifts, a, b);

        if (swapped) {
            System.out.println("Array after swapping elements at indices " + a + " and " + b + ": "
                    + GiftExchanger.arrayToString(gifts));
        } else {
            System.out.println("Invalid indices. Swap operation aborted.");
        }
    }
}