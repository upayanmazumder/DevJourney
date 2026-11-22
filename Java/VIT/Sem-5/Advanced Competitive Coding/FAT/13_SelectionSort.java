import java.util.Scanner;

public class Main {

  static void selectionSort(int[] a) {
    int n = a.length;
    for (int i = 0; i < n - 1; i++) {
      int min = i;
      for (int j = i + 1; j < n; j++) {
        if (a[j] < a[min]) min = j;
      }
      int t = a[min];
      a[min] = a[i];
      a[i] = t;
    }
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    if (!sc.hasNextInt()) return;

    int n = sc.nextInt();
    int[] a = new int[n];
    for (int i = 0; i < n; i++) a[i] = sc.nextInt();

    selectionSort(a);

    StringBuilder out = new StringBuilder();
    for (int i = 0; i < n; i++) {
      if (i > 0) out.append(' ');
      out.append(a[i]);
    }
    out.append('\n');
    System.out.print(out);
  }
}
