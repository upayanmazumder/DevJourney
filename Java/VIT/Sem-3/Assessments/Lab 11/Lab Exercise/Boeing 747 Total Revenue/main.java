class Airline {
    protected double ticketCost;

    void setCost(double cost) {
        this.ticketCost = cost;
    }

    double getCost() {
        return ticketCost;
    }
}

class Indigo extends Airline {
    protected int seatAvailability;

    void setSeatAvailability(int seats) {
        this.seatAvailability = seats;
    }

    int getSeatAvailability() {
        return seatAvailability;
    }
}

class Boeing747 extends Indigo {
    double calculateTotalRevenue() {
        return ticketCost * seatAvailability;
    }

    void displayRevenue() {
        System.out.printf("Ticket Cost: Rs. %.1f\n", getCost());
        System.out.println("Seat Availability: " + getSeatAvailability() + " seats");
        System.out.printf("Total Revenue: Rs. %.1f\n", calculateTotalRevenue());
    }
}
