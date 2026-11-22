import java.util.Scanner;

public class Main {

  static void swap(int[] a, int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
  }

  // Lomuto partition: elements smaller than the pivot go to its left.
  static int partition(int[] a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
      if (a[j] < pivot) {
        i++;
        swap(a, i, j);
      }
    }
    swap(a, i + 1, high);
    return i + 1;
  }

  static void quickSort(int[] a, int low, int high) {
    if (low < high) {
      int p = partition(a, low, high);
      quickSort(a, low, p - 1);
      quickSort(a, p + 1, high);
    }
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    if (!sc.hasNextInt()) return;

    int n = sc.nextInt();
    int[] a = new int[n];
    for (int i = 0; i < n; i++) a[i] = sc.nextInt();

    if (n > 0) quickSort(a, 0, n - 1);

    StringBuilder out = new StringBuilder();
    for (int i = 0; i < n; i++) {
      if (i > 0) out.append(' ');
      out.append(a[i]);
    }
    out.append('\n');
    System.out.print(out);
  }
}
