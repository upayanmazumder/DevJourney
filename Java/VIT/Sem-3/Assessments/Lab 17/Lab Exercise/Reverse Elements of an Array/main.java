import java.util.Scanner;

class ArrayReverser {

    public static <T> void reverse(T[] array) {
        int left = 0;
        int right = array.length - 1;
        while (left < right) {
            T temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            left++;
            right--;
        }
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

        Integer[] array = new Integer[n];
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }

        scanner.close();

        Integer[] originalArray = new Integer[n];
        System.arraycopy(array, 0, originalArray, 0, n);

        System.out.println(ArrayReverser.arrayToString(originalArray));

        ArrayReverser.reverse(array);

        System.out.println(ArrayReverser.arrayToString(array));
    }
}