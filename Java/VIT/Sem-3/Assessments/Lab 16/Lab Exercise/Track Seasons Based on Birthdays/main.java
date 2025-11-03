import java.io.*;
import java.util.*;

class Birthday implements Serializable {
    int month, day;

    Birthday(int month, int day) {
        this.month = month;
        this.day = day;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int month = sc.nextInt();
        int day = sc.nextInt();
        sc.close();
        Birthday b = new Birthday(month, day);
        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("birthdays.ser"))) {
            out.writeObject(b);
        } catch (IOException e) {
            return;
        }
        Birthday obj = null;
        try (ObjectInputStream in = new ObjectInputStream(new FileInputStream("birthdays.ser"))) {
            obj = (Birthday) in.readObject();
        } catch (IOException | ClassNotFoundException e) {
            return;
        }
        if (obj.month < 1 || obj.month > 12)
            System.out.println("Invalid month");
        else if (obj.month == 12 || obj.month == 1 || obj.month == 2)
            System.out.println("Winter");
        else if (obj.month >= 3 && obj.month <= 5)
            System.out.println("Spring");
        else if (obj.month >= 6 && obj.month <= 8)
            System.out.println("Summer");
        else
            System.out.println("Fall");
    }
}
