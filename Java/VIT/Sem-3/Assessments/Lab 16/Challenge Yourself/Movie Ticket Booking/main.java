import java.io.*;
import java.util.*;

class Ticket implements Serializable {
    int id;
    String movie;
    String seat;
    double price;

    Ticket(int id, String movie, String seat, double price) {
        this.id = id;
        this.movie = movie;
        this.seat = seat;
        this.price = price;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Ticket[] t = new Ticket[n];
        for (int i = 0; i < n; i++) {
            int id = sc.nextInt();
            String movie = sc.next();
            String seat = sc.next();
            double price = sc.nextDouble();
            t[i] = new Ticket(id, movie, seat, price);
        }
        String search = sc.next();
        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("tickets.ser"))) {
            out.writeObject(t);
        } catch (IOException e) {
            return;
        }
        Ticket[] tickets = null;
        try (ObjectInputStream in = new ObjectInputStream(new FileInputStream("tickets.ser"))) {
            tickets = (Ticket[]) in.readObject();
        } catch (Exception e) {
            return;
        }
        int count = 0;
        for (Ticket ticket : tickets) {
            if (ticket.movie.equals(search))
                count++;
        }
        if (count == 0)
            System.out.println("No tickets booked for this movie");
        else
            System.out.println(count);
    }
}
