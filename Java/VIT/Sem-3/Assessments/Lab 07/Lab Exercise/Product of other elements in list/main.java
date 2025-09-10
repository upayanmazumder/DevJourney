import java.util.*;

class ProductExceptSelf {
    void computeProduct(int[] arr) {
        int n = arr.length;
        long totalProduct = 1;
        int zeroCount = 0;
        for (int x : arr) {
            if (x != 0)
                totalProduct *= x;
            else
                zeroCount++;
        }
        for (int i = 0; i < n; i++) {
            if (zeroCount > 1)
                System.out.print(0 + " ");
            else if (zeroCount == 1)
                System.out.print((arr[i] == 0 ? totalProduct : 0) + " ");
            else
                System.out.print(totalProduct / arr[i] + " ");
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
        ProductExceptSelf pes = new ProductExceptSelf();
        pes.computeProduct(arr);
    }
}
