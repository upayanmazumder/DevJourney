import java.util.*;

class ArrayRotationChecker {
    int[] readArray(Scanner sc, int n) {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();
        return arr;
    }

    int findRotationCount(int[] arr) {
        int n = arr.length;
        int drops = 0, dropIndex = -1;
        for (int i = 0; i < n; i++) {
            int next = arr[(i + 1) % n];
            if (arr[i] > next) {
                drops++;
                dropIndex = i;
            }
        }
        if (drops == 0)
            return 0;
        if (drops == 1)
            return n - dropIndex - 1;
        return -1;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayRotationChecker checker = new ArrayRotationChecker();
        int[] arr = checker.readArray(sc, n);
        System.out.println(checker.findRotationCount(arr));
    }
}
