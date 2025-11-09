import java.io.*;
import java.util.*;

class Student {
    private int rno;
    private int mark1;
    private int mark2;
    private int mark3;

    public int getRno() {
        return rno;
    }

    public void setRno(int rno) {
        this.rno = rno;
    }

    public int getMark1() {
        return mark1;
    }

    public void setMark1(int mark1) {
        this.mark1 = mark1;
    }

    public int getMark2() {
        return mark2;
    }

    public void setMark2(int mark2) {
        this.mark2 = mark2;
    }

    public int getMark3() {
        return mark3;
    }

    public void setMark3(int mark3) {
        this.mark3 = mark3;
    }

    public int getTotalMarks() {
        return mark1 + mark2 + mark3;
    }
}

class StudentResult {
    public static void findSubjectToppers(Student[] students) {
        int max1 = -1, max2 = -1, max3 = -1;
        int r1 = 0, r2 = 0, r3 = 0;

        for (Student s : students) {
            if (s.getMark1() > max1) {
                max1 = s.getMark1();
                r1 = s.getRno();
            }
            if (s.getMark2() > max2) {
                max2 = s.getMark2();
                r2 = s.getRno();
            }
            if (s.getMark3() > max3) {
                max3 = s.getMark3();
                r3 = s.getRno();
            }
        }

        System.out.println(r1 + " " + max1);
        System.out.println(r2 + " " + max2);
        System.out.println(r3 + " " + max3);
    }

    public static void findOverallTopper(Student[] students) {
        int maxTotal = -1, r = 0;
        for (Student s : students) {
            int total = s.getTotalMarks();
            if (total > maxTotal) {
                maxTotal = total;
                r = s.getRno();
            }
        }
        System.out.println(r + " " + maxTotal);
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        Student[] students = new Student[n];
        for (int i = 0; i < n; i++) {
            students[i] = new Student();
            students[i].setRno(sc.nextInt());
            students[i].setMark1(sc.nextInt());
            students[i].setMark2(sc.nextInt());
            students[i].setMark3(sc.nextInt());
        }

        for (Student s : students) {
            System.out.println(s.getTotalMarks());
        }

        StudentResult.findSubjectToppers(students);
        StudentResult.findOverallTopper(students);
    }
}
