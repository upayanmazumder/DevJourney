import java.util.Scanner;

class InvalidCreditCardException extends Exception {
    public InvalidCreditCardException(String message) {
        super(message);
    }
}

class Main {
    static void validateCreditCard(String card) throws InvalidCreditCardException {
        if (card.length() != 16)
            throw new InvalidCreditCardException("Error: Invalid credit card number length.");
        for (char c : card.toCharArray()) {
            if (!Character.isDigit(c))
                throw new InvalidCreditCardException("Error: Invalid credit card number format.");
        }
        System.out.println("Payment information updated successfully!");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String card = sc.nextLine();
        try {
            validateCreditCard(card);
        } catch (InvalidCreditCardException e) {
            System.out.println(e.getMessage());
        }
    }
}