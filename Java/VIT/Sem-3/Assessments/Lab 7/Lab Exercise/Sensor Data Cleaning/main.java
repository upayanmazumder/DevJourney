import java.util.*;

class DuplicateRemover {
    void removeConsecutiveDuplicates(int[] arr) {
        if (arr.length == 0)
            return;
        System.out.print(arr[0] + " ");
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] != arr[i - 1])
                System.out.print(arr[i] + " ");
        }
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();
        DuplicateRemover dr = new DuplicateRemover();
        dr.removeConsecutiveDuplicates(arr);
    }
}
