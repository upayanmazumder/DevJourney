import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String name = sc.nextLine();
        int age = Integer.parseInt(sc.nextLine());
        String timeSlot = sc.nextLine();
        String ticketType = sc.nextLine();
        double price = 0.0;

        if (timeSlot.equalsIgnoreCase("Morning")) {
            price = 100;
        } else if (timeSlot.equalsIgnoreCase("Evening")) {
            price = 150;
        } else {
            System.out.println("Invalid time slot entered.");
            System.out.println(0.0);
            return;
        }

        if (ticketType.equalsIgnoreCase("Premium")) {
            price += 50;
        }

        if (age < 12) {
            price *= 0.5;
        } else if (age >= 60) {
            price *= 0.7;
        }

        System.out.println(price);
    }
}