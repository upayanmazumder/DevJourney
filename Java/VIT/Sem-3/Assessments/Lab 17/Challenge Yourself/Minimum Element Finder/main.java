import java.util.Scanner;
import java.util.Arrays;

interface Min<T extends Comparable<T>> {
    T findMin(T[] array);
}

class MinFinder<T extends Comparable<T>> implements Min<T> {
    @Override
    public T findMin(T[] array) {
        Arrays.sort(array);
        return array[0];
    }
}

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        Integer[] integerArray = new Integer[n];
        for (int i = 0; i < n; i++) {
            integerArray[i] = scanner.nextInt();
        }

        scanner.close();

        MinFinder<Integer> integerMinFinder = new MinFinder<>();
        Integer minInteger = integerMinFinder.findMin(integerArray);

        System.out.println(minInteger);
    }
}