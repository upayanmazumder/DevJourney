import java.io.*;
import java.util.*;

class Product implements Serializable {
    int id;
    String name;
    double cost;

    Product(int id, String name, double cost) {
        this.id = id;
        this.name = name;
        this.cost = cost;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Product> products = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int id = sc.nextInt();
            sc.nextLine();
            String name = sc.nextLine();
            double cost = sc.nextDouble();
            products.add(new Product(id, name, cost));
        }
        sc.close();
        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("products.dat"))) {
            out.writeObject(products);
            System.out.println("Successfully serialized " + n + " products to products.dat");
        } catch (IOException e) {
            return;
        }
        ArrayList<Product> list = null;
        try (ObjectInputStream in = new ObjectInputStream(new FileInputStream("products.dat"))) {
            list = (ArrayList<Product>) in.readObject();
        } catch (IOException | ClassNotFoundException e) {
            return;
        }
        double total = 0;
        for (Product p : list)
            total += p.cost;
        System.out.println("Total cost of all products: " + total);
    }
}
