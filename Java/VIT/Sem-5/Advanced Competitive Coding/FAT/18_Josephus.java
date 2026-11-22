// Build the Josephus survivor from a one-person circle to a circle of size n.
// Reduce the step modulo each size and convert the final index to a 1-based position.

import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    if (!sc.hasNextInt()) return;

    int n = sc.nextInt();
    long k = sc.nextLong();

    // survivor is the 0-based index of the survivor for the current size.
    long survivor = 0;
    for (long size = 2; size <= n; size++) {
      survivor = (survivor + k % size) % size;
    }

    System.out.println(survivor + 1);
  }
}
