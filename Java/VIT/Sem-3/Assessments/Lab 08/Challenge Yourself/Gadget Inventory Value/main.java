import java.util.*;

class Gadget {
    public String name;
    public double unitPrice;
    public int quantity;
    public double handlingCost;

    // Default constructor (needed for footer)
    public Gadget() {
    }

    // Method to compute total value for this gadget
    public double getTotalValue() {
        return (unitPrice * quantity) + (handlingCost * quantity);
    }

    // Static method as expected in footer
    public static double calculateTotalValue(Gadget[] gadgets) {
        double totalValue = 0.0;
        int totalQuantity = 0;
        double totalUnitPriceSum = 0.0;

        for (Gadget g : gadgets) {
            if (g == null)
                continue;
            totalValue += g.getTotalValue();
            totalQuantity += g.quantity;
            totalUnitPriceSum += g.unitPrice;
        }

        // Apply discounts
        if (totalValue > 1000.00) {
            totalValue *= 0.75; // 25% discount
        } else if (totalValue > 500.00) {
            totalValue *= 0.85; // 15% discount
        }

        if (totalQuantity > 100) {
            totalValue *= 0.90; // additional 10% discount
        }

        // Average unit price
        double avgUnitPrice = totalUnitPriceSum / gadgets.length;
        if (avgUnitPrice < 20.00) {
            totalValue *= 1.05; // 5% surcharge
        }

        return totalValue;
    }
}