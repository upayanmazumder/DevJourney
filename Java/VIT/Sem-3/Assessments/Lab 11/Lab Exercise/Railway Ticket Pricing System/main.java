class Ticket {
    public double calculatePrice(int distance) {
        return distance * 0.05;
    }
}

class SeniorCitizenTicket extends Ticket {
    @Override
    public double calculatePrice(int distance) {
        return super.calculatePrice(distance) * 0.9;
    }
}