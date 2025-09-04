import java.util.*;

class ZeroPusher {
    void moveZerosToEnd(int[] arr) {
        int n = arr.length, idx = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0)
                arr[idx++] = arr[i];
        }
        while (idx < n)
            arr[idx++] = 0;
        for (int i = 0; i < n; i++)
            System.out.print(arr[i] + " ");
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();
        ZeroPusher zp = new ZeroPusher();
        zp.moveZerosToEnd(arr);
    }
}
