// Normalize the rotation distance and divide the array into left and right blocks.
// Swap equal-sized pieces until both remaining blocks match, then perform the final swap.

import java.util.Scanner;

public class Main {
  static void swap(int[] a, int first, int second, int count) {
    for (int k = 0; k < count; k++) {
      int temp = a[first + k];
      a[first + k] = a[second + k];
      a[second + k] = temp;
    }
  }

  static void rotate(int[] a, int distance) {
    int n = a.length;
    if (n == 0) return;
    int d = Math.floorMod(distance, n);
    if (d == 0) return;
    int left = d;
    int right = n - d;
    while (left != right) {
      if (left < right) {
        swap(a, d - left, d + right - left, left);
        right -= left;
      } else {
        swap(a, d - left, d, right);
        left -= right;
      }
    }
    swap(a, d - left, d, left);
  }

  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    int n = input.nextInt();
    int distance = input.nextInt();
    int[] a = new int[n];
    for (int i = 0; i < n; i++) a[i] = input.nextInt();
    rotate(a, distance);
    for (int i = 0; i < n; i++) {
      if (i > 0) System.out.print(" ");
      System.out.print(a[i]);
    }
    System.out.println();
  }
}
