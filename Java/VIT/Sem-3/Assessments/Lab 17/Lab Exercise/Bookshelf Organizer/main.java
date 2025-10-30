import java.util.Scanner;

class BookSearch {
    public static <T extends Comparable<T>> int binarySearch(T[] array, T key) {
        int low = 0;
        int high = array.length - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int comparison = array[mid].compareTo(key);

            if (comparison == 0) {
                return mid;
            } else if (comparison < 0) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        Integer[] bookIDs = new Integer[n];

        for (int i = 0; i < n; i++) {
            bookIDs[i] = scanner.nextInt();
        }

        int searchID = scanner.nextInt();

        scanner.close();

        int index = BookSearch.binarySearch(bookIDs, searchID);

        if (index != -1) {
            System.out.println("Element found at index: " + index);
        } else {
            System.out.println("Element not found in the array.");
        }
    }
}