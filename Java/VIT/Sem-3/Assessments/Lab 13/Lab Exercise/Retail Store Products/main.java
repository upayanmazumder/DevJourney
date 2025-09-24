import java.util.Scanner;

class Product {
    String name;
    double price;
    int quantity;

    public Product(String name, double price, int quantity) {
        if (name.length() > 25)
            throw new IllegalArgumentException("Product name should be 25 characters or less");
        if (price <= 0)
            throw new IllegalArgumentException("Price should be a positive value");
        if (quantity < 0)
            throw new IllegalArgumentException("Quantity should be a non-negative integer");
        this.name = name;
        this.price = price;
        this.quantity = quantity;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        try {
            String name = sc.nextLine();
            double price = Double.parseDouble(sc.nextLine());
            int quantity = Integer.parseInt(sc.nextLine());
            Product p1 = new Product(name, price, quantity);
            System.out.println("Product details are valid");
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
    }
}