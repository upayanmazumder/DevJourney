import java.util.Scanner;
import java.util.Arrays;

class ArraySorter<T extends Comparable<T>> {
    public void sortArray(T[] array) {
        Arrays.sort(array);
    }
}

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        Double[] doubles = new Double[N];
        for (int i = 0; i < N; i++) {
            doubles[i] = scanner.nextDouble();
        }
        scanner.close();

        ArraySorter<Double> sorter = new ArraySorter<>();
        sorter.sortArray(doubles);

        StringBuilder result = new StringBuilder("[");
        for (int i = 0; i < N; i++) {
            result.append(String.format("%.2f", doubles[i]));
            if (i < N - 1) {
                result.append(", ");
            }
        }
        result.append("]");
        System.out.println(result.toString());
    }
}