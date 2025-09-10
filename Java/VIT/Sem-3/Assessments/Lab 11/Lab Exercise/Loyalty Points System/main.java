class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int amountSpent = scanner.nextInt();
        scanner.nextLine(); // consume newline
        String isPremium = scanner.nextLine().trim();

        Customer customer;
        if (isPremium.equalsIgnoreCase("yes")) {
            customer = new PremiumCustomer();
        } else {
            customer = new Customer();
        }

        int loyaltyPoints = customer.calculateLoyaltyPoints(amountSpent);
        System.out.println(loyaltyPoints);

        scanner.close();
    }
}
