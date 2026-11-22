// Sort student records by name, then age, then roll number to resolve ties.
// Print each record as roll, name, and age in that order.

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {

  static class Student {
    final int roll;
    final String name;
    final int age;

    Student(int roll, String name, int age) {
      this.roll = roll;
      this.name = name;
      this.age = age;
    }
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    if (!sc.hasNextInt()) return;

    int n = sc.nextInt();
    List<Student> students = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      students.add(new Student(sc.nextInt(), sc.next(), sc.nextInt()));
    }

    students.sort(
        Comparator.comparing((Student s) -> s.name)
            .thenComparingInt(s -> s.age)
            .thenComparingInt(s -> s.roll));

    StringBuilder out = new StringBuilder();
    for (Student s : students) {
      out.append(s.roll).append(' ').append(s.name).append(' ').append(s.age).append('\n');
    }
    System.out.print(out);
  }
}
